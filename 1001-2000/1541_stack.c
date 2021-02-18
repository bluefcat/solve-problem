#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Stack{
	int capacity;
	int size;
	char data[51][7];
} Stack;

Stack* create_stack(int capacity);
int is_empty(Stack* target);
int is_full(Stack* target);
int push_stack(Stack* target, const char* data);
char* top_stack(Stack* target);
char* pop_stack(Stack* target);

int main(){
	Stack* parser = create_stack(51);
    
    char infix_expr[51] = { 0, };
	char postfix_expr[51][7] = { 0, };

	scanf("%s", infix_expr);
	
	//중위 표기법을 후위 표기법으로 변환한다.
	char* p = infix_expr;
	int postfix_idx = 0;
	int sidx = 0, eidx = 0;

	while(*p){
		if(*p == '+' || *p == '-'){
			//add number
			strncpy(postfix_expr[postfix_idx++], infix_expr+sidx, eidx-sidx);
			sidx = eidx+1;
			
			char tmp[2] = { 0, };
			tmp[0] = p[0];
			if(!top_stack(parser)){
				push_stack(parser, tmp);
			}	
			else if(*p == '+'){
				push_stack(parser, tmp);
			}
			//case *p == '-'
			else{
				while(top_stack(parser)){
					strcpy(postfix_expr[postfix_idx++], pop_stack(parser));
				}
				push_stack(parser, tmp);
			}
		}
		eidx ++; p++;		
	}
	strcpy(postfix_expr[postfix_idx++], infix_expr+sidx);
	while(!is_empty(parser)){
		strcpy(postfix_expr[postfix_idx++], pop_stack(parser));
	}

	//후위표기법으로 변환한 식을 계산한다.
	for(int i = 0; i < postfix_idx; i ++){
		char* n = postfix_expr[i];
		if(*n == '+' || *n == '-'){
			int y = atoi(pop_stack(parser));
			int x = atoi(pop_stack(parser));
			
			char tmp[7] = { 0, };
			if(*n == '+'){
				sprintf(tmp, "%d", x+y);
				push_stack(parser, tmp);
			}
			else if(*n == '-'){
				sprintf(tmp, "%d", x-y);
				push_stack(parser, tmp);
			}
		}
		else{
			push_stack(parser, postfix_expr[i]);
		}
	}

	//결과값을 출력한다.
	printf("%d\n", atoi(pop_stack(parser)));
    
	free(parser);
	return 0;
}

Stack* create_stack(int capacity){
	Stack* result = (Stack*)malloc(sizeof(Stack));
	result->capacity = capacity;
	result->size = 0;

	return result;
}

int is_empty(Stack* target){
	return (target->size == 0);
}

int is_full(Stack* target){
	return (target->size == target->capacity);
}

int push_stack(Stack* target, const char* data){
	if(is_full(target)) return 0;
	for(int i = 0; i < 7; i ++) target->data[target->size][i] = 0; 
	strcpy(target->data[target->size++], data);
	return 1;
}

char* top_stack(Stack* target){
	if(is_empty(target)) return NULL;
	return target->data[target->size-1];
}

char* pop_stack(Stack* target){
	char* result = top_stack(target);
	if(result != NULL) target->size --;
	return result;
}