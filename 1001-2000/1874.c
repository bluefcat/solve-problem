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

int push_stack(Stack* target, int data, char* answer){
	if(is_full(target)) return 0;
	answer[0] = '+';
	int idx = target->size;
	target->data[idx] = data;
	target->size ++;

	return 1;
}

int top_stack(Stack* target){
	if(is_empty(target)) return -1;
	
	return target->data[target->size-1];
}

int pop_stack(Stack* target, char* answer){
	if(is_empty(target)) return -1;
	answer[0] = '-';
	target->size --;
	return target->data[target->size];
}

int main(){
	Stack* stack;
	char answer[1000000] = { 0, };
	char oper[6] = { 0, };

	int n;
	scanf("%d", &n);
	stack = create_stack(n);
	
	int idx = 1, aidx = 0;
	for(int i = 0; i < n; i ++){
		int t;
		scanf("%d", &t);

		while(t > top_stack(stack)){
			push_stack(stack, idx++, answer+aidx);
			aidx ++;
		}

		if(t == top_stack(stack)){
			pop_stack(stack, answer+aidx);
			aidx ++;
		}
	}

	if(top_stack(stack) != -1){
		printf("NO\n");
	}
	else{
		for(int i = 0; i < aidx; i ++){
			printf("%c\n", answer[i]);
		}
	}

	delete_stack(stack);
	return 0;
}
