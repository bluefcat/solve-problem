#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "range.h"

void print_range_token(RANGE_TOKEN* result){
	printf("value name: %s\nlower bound: %d, upper bound: %d\n",
			result->value_name,
			result->value_min,
			result->value_max
		  );

	return;
}

void print_chain_token(CHAIN_TOKEN* result){
	TOKEN* target = result;
	
	while(target->range_token != NULL){
		printf("[%s] > ", target->range_token->value_name);
		target = target->child_header;
	}
	printf("\n");

	printf("===\n");
	target = result;
	
	while(target->range_token != NULL){
		print_range_token(target->range_token);
		target = target->child_header;
	}

	printf("===\n");
	return;
}

void print_token(TOKEN* result){
	TOKEN* target = result;

	while(target->range_token != NULL){
		printf("-------\n");
		print_range_token(target->range_token);
		print_chain_token(target);
		printf("-------\n");
		target = target->next_token;
	} 
	
	return;
}

int parse_range_token_(int fd, RANGE_TOKEN* result){
	/*
	   this function is parsing one signle token

	args:
		fd: 		open file descriptor
		result:		save a parsing result

	results:
		mode:		parsign mode
	 */

	int current_mode = FINDING_NAME;

	int index_buffer = 0;
	char buffer[1] = { 0, };
	char name_buffer[MAXLEN] = { 0, };
	char num_buffer[MAXLEN] = { 0, };

	while(read(fd, buffer, 1)){
		switch(current_mode){
			case FINDING_NAME:
				if(buffer[0] == ':'){
					name_buffer[index_buffer] = '\0';
					result->value_name = (char*)malloc(sizeof(char)*strlen(name_buffer));
					strcpy(result->value_name, name_buffer);
					
					//reset
					index_buffer = 0;
					INIT_BUFFER(name_buffer, MAXLEN);
					
					//mode chanage
					current_mode = FINDING_MIN;

				} 
				else if(buffer[0] == '\n' || buffer[0] == ' '){
					//idle status 
				} else {
					name_buffer[index_buffer ++] = buffer[0];
				}
				break;

			case FINDING_MIN:
				if(buffer[0] == ','){
					result->value_min = atoi(num_buffer);

					//result
					index_buffer = 0;
					INIT_BUFFER(num_buffer, MAXLEN);
					current_mode = FINDING_MAX;
				}
				else if(buffer[0] == '(' || buffer[0] == ' '){
					//idle status
				}
				else{
					num_buffer[index_buffer ++] = buffer[0];
				}
				break;

			case FINDING_MAX:
				if(buffer[0] == ')'){
					result->value_max = atoi(num_buffer);

					//reset
					index_buffer = 0;
					INIT_BUFFER(num_buffer, MAXLEN);
					current_mode = NONE;
					
					goto PRT_END;
				}
				else if(buffer[0] == ' '){
					//idle status
				}
				else{
					num_buffer[index_buffer ++] = buffer[0];
				}
				break;

			default:
				break;
		}

	}

	PRT_END:
	return current_mode;
}

int parse_chain_token_(int fd, RANGE_TOKEN* tokens, CHAIN_TOKEN* target, int size){
	/*
	   this function is parsing one signle chain token

	args:
		fd: 		open file descriptor
		result:		save a parsing result

	results:
		mode:		parsign mode
	 */

	//inin valuable
	int current_mode = FINDING_NAME;

	char buffer[1] = { 0, };
	char name_buffer[MAXLEN] = { 0, };

	int index_buffer = 0;


	//init target
	target->child_header = (CHAIN_TOKEN*)malloc(sizeof(CHAIN_TOKEN));

	CHAIN_TOKEN* child_target = target->child_header;

	while(read(fd, buffer, 1)){
		switch(current_mode){
			//key part
			case FINDING_NAME:
				if(buffer[0] == ':'){
					name_buffer[index_buffer] = '\0';
					target->range_token = find_token_(name_buffer, tokens, size);


					//reset
					index_buffer = 0;
					INIT_BUFFER(name_buffer, MAXLEN);

					current_mode = FINDING_VALUE;

				}
				else if(buffer[0] == '\n' || buffer[0] == ' '){
					//idle status
				}
				else {
					name_buffer[index_buffer ++] = buffer[0];
				}
				break;
			
			//value part
			case FINDING_VALUE:
				//value accept
				if(buffer[0] == '}'){
					name_buffer[index_buffer] = '\0';
					
					child_target->range_token = find_token_(name_buffer, tokens, size);

					//reset
					index_buffer = 0;
					INIT_BUFFER(name_buffer, MAXLEN);

					current_mode = NONE;
					child_target->child_header = (CHAIN_TOKEN*)malloc(sizeof(CHAIN_TOKEN));
					child_target = child_target->child_header;

					goto PCT_END;
				}
				//value accept
				else if(buffer[0] == ','){
					name_buffer[index_buffer] = '\0';

					child_target->range_token = find_token_(name_buffer, tokens, size);
					
					//result
					index_buffer = 0;
					INIT_BUFFER(name_buffer, MAXLEN);

					current_mode = FINDING_VALUE;
					child_target->child_header = (CHAIN_TOKEN*)malloc(sizeof(CHAIN_TOKEN));
					child_target = child_target->child_header;

				}
				else if(buffer[0] == '{' || buffer[0] == ' ' || buffer[0] == '\n' || buffer[0] == '\t'){
					//idle status
				}
				else{
					name_buffer[index_buffer ++] = buffer[0];
				}

				break;

			default:
				break;

		}

	}
	
	PCT_END:
	child_target->range_token = NULL;
	return current_mode;
}

RANGE_TOKEN* find_token_(const char* name, RANGE_TOKEN* tokens, int size){
	for(int i = 0; i < size; i ++){
		if(strcmp(name, tokens[i].value_name) == 0) return (tokens+i);
	}
	return NULL;
}

TOKEN* parse_data_(int fd){
	//init fd
	int token_count = 0;

	int status = 0;
	int part = FINDING_RANGE;
	int current_mode = part;

	char buffer[1] = { 0, };
	lseek(fd, 0, SEEK_SET);
	
	RANGE_TOKEN* tokens = (RANGE_TOKEN*)malloc(sizeof(RANGE_TOKEN)*16);
	
	TOKEN* result = (TOKEN*)malloc(sizeof(TOKEN));
	TOKEN* target = result;

	do{	
		switch(current_mode){
			case FINDING_RANGE:
				current_mode = parse_range_token_(fd, tokens + token_count);
				token_count ++;

				break;

			case FINDING_CHAIN:
				if(target == NULL) target = (CHAIN_TOKEN*)malloc(sizeof(CHAIN_TOKEN));
				current_mode = parse_chain_token_(fd, tokens, target, token_count);
				
				target->next_token = (CHAIN_TOKEN*)malloc(sizeof(CHAIN_TOKEN));
				target = target->next_token;
				break;

			default:	//NONE, ERROR, ACCEPT
				status = read(fd, buffer, 1);
				if(status == 0){
					current_mode = ACCEPT;
				}
				else if(buffer[0] == ','){
					current_mode = part;
				}
				else if(buffer[0] == ';'){	// separate mode 
					part = FINDING_CHAIN;
					current_mode = part;
				}
		}
	} while(current_mode != ACCEPT);

	//function normal end 
	return result;
}

TOKEN* create_token(const char* file_name){
	int fd = open(file_name, O_RDONLY);
	
	TOKEN* result = NULL;
	result = parse_data_(fd);
	
	//function normal end
	close(fd);
	return result;
}

int generate_token(TOKEN* token){
	printf("Generate Data with Token\n");
	return 0;
}


void delete_child_(TOKEN* header){
	//this is O(n) but token have a limit token count
	TOKEN* t[16];
	int count = 0;
	
	TOKEN* target = header;
	
	while(target->range_token != NULL){
		t[count ++] = target;
		target = target->child_header;
	}

	for(int i = 0; i < count; i ++){
		free(t[i]);
	}
	
	return;
}

void delete_chain_(TOKEN* header){
	TOKEN* t[16];
	int count = 0;

	TOKEN* target = header;

	while(target->range_token != NULL){
		t[count ++] = target;
		target = target->next_token;
	}

	for(int i = 0; i < count; i ++){
		free(t[i]);
	}

	return;
}

void delete_token(TOKEN* token){
	TOKEN* target = token;
	
	while(target->range_token != NULL){
		delete_child_(target->child_header);
		target = target->next_token;
	}
	
	delete_chain_(token);

	return;
}

int main(){
	TOKEN* r = create_token("range_test.txt");

	print_token(r);
	generate_token(r);

	delete_token(r);
	return 0;
}
