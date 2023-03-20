#include <stdio.h>
#define NONE -1

char stack[151];
int head;

char string[151];
char result[151];
int cnt;

char oper[4] = { '+', '-', '*', '/' };

int is_oper(char x){
	int result = -1;
	for(int i = 0; i < 4; i ++){
		if(oper[i] == x){
			result = i;
			break;
		}
	}
	return result >> 1;
}

int main(){
	scanf("%s", string);

	char* p = string;

	while(*p){
		if(is_oper(*p) != NONE){
			if(head > 0){
				int cand = is_oper(*p);
				
				while(head > 0){
					int top = is_oper(stack[head-1]);	
					if(top >= cand) result[cnt++] = stack[--head];
					else break;
				}
				stack[head++] = *p;

			}
			else{
				stack[head++] = *p;
			}
		}
		else if(*p == '(') stack[head++] = *p;
		else if(*p == ')'){
			while(stack[head-1] != '('){
				result[cnt++] = stack[--head];
			}
			head--;
		}
		else result[cnt++] = *p;
		
		//for(int i = 0; i < head; i ++){
		//	printf("%c %d\t", stack[i], is_oper(stack[i]));
		//}
		//printf("\n");

		p ++;
	}
	
	while(head >= 0){
		result[cnt++] = stack[--head];
	}
	
	result[cnt] = 0;

	printf("%s\n", result);
	
	return 0;
}
