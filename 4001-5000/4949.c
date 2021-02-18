#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Stack{
	int capacity;
	int size;
	char data[101];
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

    char braket[101] = { 0, };
	stack = create_stack(101);
	
    while(1){
        scanf("%[^\n]s", braket);
        while(getchar() != '\n');

        int n = strlen(braket);
        if(n == 1 && braket[0] == '.') break;

        int i = 0;
        for(i = 0; i < n; i ++){
        if(braket[i] == '('){
                push_stack(stack, '(');
            }
            else if(braket[i] == '['){
                push_stack(stack, '[');
            }
            else if(braket[i] == ')'){
                if(top_stack(stack) != '(') break;
                pop_stack(stack);
            }
            else if(braket[i] == ']'){
                if(top_stack(stack) != '[') break;
                pop_stack(stack);
            }
            else{
                //nothing
            }
        }

        if(top_stack(stack) == -1 && i == n){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }

        while(!is_empty(stack)){
            pop_stack(stack);
        }
    }

	
	delete_stack(stack);
	return 0;
}