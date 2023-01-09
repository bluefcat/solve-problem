#include <stdio.h>
#include <string.h>

#define MAXSTRING 31
char string[MAXSTRING];

int end_bracket(int start){
	if(start >= strlen(string)) return -1;
	int result = -1;

	char stack[MAXSTRING] = { 0, };
	int head = 0;

	char* p = string + start;
	do{
		if(*p == '(' || *p == '[') stack[head++] = *p;
		else if(*p == ')' && stack[head-1] == '(') head --;
		else if(*p == ']' && stack[head-1] == '[') head --;
		else return -1;

		p++; result ++;
	}while(head != 0);

	return (result != -1)? start + result + 1: result;
}

int correct(int start, int end){
	if(start >= strlen(string)) return -1;
	int result = -1;

	char stack[MAXSTRING] = { 0, };
	int head = 0;

	char* p = string + start;
	do{
		if(*p == '(' || *p == '[') stack[head++] = *p;
		else if(*p == ')' && stack[head-1] == '(') head --;
		else if(*p == ']' && stack[head-1] == '[') head --;
		else return -1;

		p++; result ++;
	}while(p != string + end);

	return (head != 0)? -1: 0;
}

int parser(int start, int end){
	if(start >= end) return 1;

	int mul = string[start] == '('? 2: 3;
	int sp = end_bracket(start);
	
	int a = parser(start+1, sp-1);
	int b = parser(sp, end);
	if(b == 1) b = 0;

	return mul * a + b;
}

int main(){
	scanf("%s", string);
	
	if(correct(0, strlen(string)) == -1) printf("0\n");
	else printf("%d\n", parser(0, strlen(string)));

	return 0;
}
