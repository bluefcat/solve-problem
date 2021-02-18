#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Stack{
	int capacity;
	int size;
	int* data;
} Stack;

Stack* create_stack(int capacity){
	Stack* result = (Stack*)malloc(sizeof(Stack));
	result->capacity = capacity;
	result->size = 0;
	result->data = (int*)malloc(sizeof(int)*capacity);

	return result;
}

void delete_stack(Stack* target){
	free(target->data);
	free(target);

	return ;
}

int is_empty(Stack* target){
	return target->size == 0;
}

int is_full(Stack* target){
	return target->size == target->capacity;
}

int push_stack(Stack* target, int data){
	if(is_full(target)) return 0;

	int idx = target->size;
	target->data[idx] = data;
	target->size ++;

	return 1;
}

int top_stack(Stack* target){
	if(is_empty(target)) return -1;
	
	return target->data[target->size-1];
}

int pop_stack(Stack* target){
	if(is_empty(target)) return -1;
	target->size --;
	return target->data[target->size];
}

int main(){
	Stack* stack;
	char oper[6] = { 0, };

	int n, pn = 0;
	scanf("%d", &n);
	stack = create_stack(n);
	
	for(int i = 0; i < n; i ++){
		scanf("%s", oper);

		if(!strcmp(oper, "push")){
			scanf("%d", &pn);
			push_stack(stack, pn);
		}
		else if(!strcmp(oper, "pop")){
			pn = pop_stack(stack);
			printf("%d\n", pn);
		}
		else if(!strcmp(oper, "size")){
			pn = stack->size;
			printf("%d\n", pn);
		}
		else if(!strcmp(oper, "empty")){
			pn = is_empty(stack);
			printf("%d\n", pn);
		}
		else{
			pn = top_stack(stack);
			printf("%d\n", pn);
		}
	}

	delete_stack(stack);
	return 0;
}
