#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ABS(X) (((X) > 0)? (X): -(X))

typedef struct _Queue{
	int capacity;
	int front;
	int back;
	int size;
	int* data;
} Queue;

Queue* create_queue(int capacity){
	Queue* result = (Queue*)malloc(sizeof(Queue));
	
	result->capacity = capacity;
	result->front = 0;
	result->back = 0;
	result->data = (int*)malloc(sizeof(int)*(capacity+1));

	return result;
}

void delete_queue(Queue* target){
	free(target->data);
	free(target);

	return ;
}

int is_empty(Queue* target){
	return target->front == target->back;
}

int is_full(Queue* target){
	return target->size == target->capacity;
}

int front_queue(Queue* target){
	if(is_empty(target)) return -1;
	return target->data[target->front];
}

int back_queue(Queue* target){
	if(is_empty(target)) return -1;
	return target->data[target->back-1];
}

int push_queue(Queue* target, int data){
	if(is_full(target)) return 0;
	target->data[target->back++] = data;
	
	target->back %= target->capacity+1;
	target->size ++;
	return 1;
}

int pop_queue(Queue* target){
	if(is_empty(target)) return -1;
	
	int result = target->data[target->front++];
	
	target->front %= target->capacity+1;
	target->size --;
	return result;
}

int main(){
	Queue* queue;
	
	int n, pn = 0;
	scanf("%d", &n);

	queue = create_queue(n);
	
	for(int i = 0; i < n; i ++){
		char oper[6] = { 0, };
		scanf("%s", oper);

		if(strcmp(oper, "push") == 0){
			scanf("%d", &pn);
			push_queue(queue, pn); 
		}
		else if(strcmp(oper, "pop") == 0){
			printf("%d\n", pop_queue(queue));
		}
		else if(strcmp(oper, "size") == 0){
			printf("%d\n", queue->size);
		}
		else if(strcmp(oper, "empty") == 0){
			printf("%d\n", is_empty(queue));
		}
		else if(strcmp(oper, "front") == 0){
			printf("%d\n", front_queue(queue));
		}
		else{
			printf("%d\n", back_queue(queue));
		}
	}
	delete_queue(queue);
	return 0;
}
