#include <stdio.h>
#include <string.h>

#define QMAX 10001
int queue[QMAX];
int head, tail;
int length;

int empty();

void push(int x){
	queue[tail++] = x;
	length ++;
	tail %= QMAX;
}

int pop(){
	if(empty()) return -1;

	int result = queue[head];
	head = (head+1)%QMAX;
	length --;
	return result;
}

int size(){
	return length;
}

int empty(){
	return length == 0? 1: 0;
}

int front(){
	if(empty()) return -1;
	return queue[head];
}

int back(){
	if(empty()) return -1;
	
	return queue[tail-1 < 0? QMAX-1: tail-1];
}

int main(){
	int n;
	scanf("%d", &n);


	for(int i = 0; i < n; i ++){
		char oper[15] = { 0, };

		scanf("%s[^ ]", oper);
		if(strcmp(oper, "push") == 0){
			int tmp = 0;
			scanf("%d", &tmp);
			push(tmp);
		}
		else if(strcmp(oper, "pop") == 0) printf("%d\n", pop());
		else if(strcmp(oper, "size") == 0) printf("%d\n", size());
		else if(strcmp(oper, "empty") == 0) printf("%d\n", empty());
		else if(strcmp(oper, "front") == 0) printf("%d\n", front());
		else if(strcmp(oper, "back") == 0) printf("%d\n", back());
	}

	return 0;
}


