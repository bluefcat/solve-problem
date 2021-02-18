#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Stack{
	int capacity;
	int size;
	char data[51];
} Stack;

Stack* create_stack(int capacity){
	Stack* result = (Stack*)malloc(sizeof(Stack));
	result->capacity = capacity;
	result->size = 0;

	return result;
}

void delete_stack(Stack* target){
	free(target);

	return ;
}

int is_empty(Stack* target){
	return target->size == 0;
}

int is_full(Stack* target){
	return target->size == target->capacity;
}

int push_stack(Stack* target, char data){
	if(is_full(target)) return 0;

	int idx = target->size;
	target->data[idx] = data;
	target->size ++;

	return 1;
}

char top_stack(Stack* target){
	if(is_empty(target)) return -1;
	
	return target->data[target->size-1];
}

char pop_stack(Stack* target){
	if(is_empty(target)) return -1;
	target->size --;
	return target->data[target->size];
}

int main(){
	Stack* stack;

    char braket[51] = { 0, };
	int T;
	scanf("%d", &T);
	stack = create_stack(51);
	
	for(int i = 0; i < T; i ++){
        scanf("%s", braket);
        int n = strlen(braket);
        int i = 0;
        for(i = 0; i < n; i ++){
            if(braket[i] == '('){
                push_stack(stack, '(');
            }
            else{
                if(pop_stack(stack) == -1) break;
            }
        }

        if(top_stack(stack) == -1 && i == n){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

        while(!is_empty(stack)){
            pop_stack(stack);
        }
	}
	
	delete_stack(stack);
	return 0;
}