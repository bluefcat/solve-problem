#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct value_{
	char name[16];
	int range[2];
} value;

typedef struct node_{
	value** vp;
	int length;
} node;

#define STACKSIZE 10
value* stack[STACKSIZE];
int stack_cursor;

int is_char(const char x){
	return ('A' <= x) && (x <= 'z') && (x != ' ') && (x != '(') && (x != ')');
}

int is_num(const char x){
	return ('0' <= x) && (x <= '9');
}

int main(){
	node n[10];
	int nidx = 0;

	value v[10];
	int idx = -1;

	char arg[256] = "( T 1 2 ( N 1 2 ( XAP 1 10 TP 5 10 ) ) )";
	char cpy[256] = { 0, };
	strcpy(cpy, arg);
	char* p = strtok(cpy, " ");
	int c = 0;

	while(p != NULL){
		char w = p[0];
		
		if(is_char(w)){
			strcpy(v[++idx].name, p);
			
			stack[++stack_cursor] = v + idx;
			printf("%d in character %s\n", stack_cursor, p);
			c = 0;
		}
		
		if(is_num(w)){
			v[idx].range[c++] = atoi(p);
		}
		
		if(w == '('){
			stack[++stack_cursor] = NULL;
			printf("%d in NULL\n", stack_cursor);
		}

		if(w == ')'){
			value* k[10];
			int c = 0;

			while(stack[stack_cursor] != NULL){
				k[c++] = stack[stack_cursor];

				stack_cursor --;
			}

			n[nidx].vp = (value**)malloc(sizeof(value*) * c);

			for(int i = 0; i < c; i ++){
				n[nidx].vp[i] = k[i];
			}
			n[nidx].length = c;

			nidx ++;
			stack_cursor --;
			printf("next search is %d\n", stack_cursor);
		}
		
		p = strtok(NULL, " ");
	}
	
	printf("\n");
	printf("argument:\n");
	printf("%s\n", arg);
	
	printf("\n");
	printf("structure:\n");
	for(int i = 0; i < nidx; i ++){
		int l = n[i].length;
		
		printf(">");
		for(int j = 0; j < l; j ++){
			printf("(%s %d %d) ", n[i].vp[j]->name, n[i].vp[j]->range[0], n[i].vp[j]->range[1]); 
		}
		printf("\n");
	}
	
	printf("\n");
	printf("create:\n");
	
	
	int max_count[10] = { 0, };
	int count[10] = { 0, };
	
	node mm[10];

	for(int i = 0; i <= (nidx-1); i ++){
		mm[i].vp = (value**)malloc(sizeof(value*) * n[nidx-i-1].length);
		
		for(int j = 0; j < n[nidx-i-1].length; j ++){
			mm[i].vp[j] = n[nidx-i-1].vp[j];
		}

		mm[i].length = n[nidx-i-1].length;	
	}

	for(int i = 0; i < nidx-1; i ++){
		max_count[i] = mm[i].vp[0]->range[1];
		printf("max count: %d\n", max_count[i]);
	}

	int i = 0;
	count[0] = 1;
	count[1] = 1;
	count[2] = 1;
	count[3] = 1;
	while(1){
		if(max_count[i]+1 != count[i])
			printf("[%d (%d/%d)]\n", i, max_count[i], count[i]);
		if(i != nidx-1){
			if(max_count[i]+1 != count[i]){
				count[i] ++;
				i ++;
			}
			else{
				count[i] = 1;
				i --;
				if(i == 0 && count[i] == max_count[i] + 1) return 0;
			}
		}
		else{
			for(int k = 0; k < mm[idx-1].length; k ++){
				printf("(%s %d %d) ", mm[idx-1].vp[k]->name, mm[idx-1].vp[k]->range[0], mm[idx-1].vp[k]->range[1]);
			}
			printf("\n===\n");
			i --;
		}
	}

	return 0;
}
