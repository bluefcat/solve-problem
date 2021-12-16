#include <stdio.h>
#include <string.h>

#define DMAX (10001+2)
int deque[DMAX];
int head, tail, length;

int empty();

void push_front(int x){
	int idx = (head - 1) < 0? DMAX-1: head-1;
	deque[idx] = x;
	head = idx;
	if(length == 0) tail = head;

	length ++;
}

void push_back(int x){
	int idx = (tail + 1) % DMAX;
	deque[idx] = x;
	tail = idx;
	if(length == 0) head = tail;

	length ++;
}

int pop_front(){
	if(empty() == 1) return -1;
	int result = deque[head];
	head = (head+1) % DMAX;
	length --;
	
	if(length == 0) tail = head;

	return result;
}

int pop_back(){
	if(empty() == 1) return -1;
	int result = deque[tail];
	tail --;
	if(tail < 0) tail = DMAX-1;
	length --;

	if(length == 0) head = tail;

	return result;
}

int front(){
	if(empty() == 1) return -1;
	return deque[head];
}

int back(){
	if(empty() == 1) return -1;
	return deque[tail];
}

int empty(){
	return length == 0? 1: 0;
}

int size(){
	return length;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		char oper[50] = { 0, };
		int target = 0;

		scanf("%s", oper);

		if(strcmp(oper, "push_front") == 0){
			scanf("%d", &target);
			push_front(target);
		}
		else if(strcmp(oper, "push_back") == 0){
			scanf("%d", &target);
			push_back(target);
		}

		else if(strcmp(oper, "pop_front") == 0) printf("%d\n", pop_front());
		
		else if(strcmp(oper, "pop_back") == 0) printf("%d\n", pop_back());

		else if(strcmp(oper, "size") == 0) printf("%d\n", size());

		else if(strcmp(oper, "empty") == 0) printf("%d\n", empty());

		else if(strcmp(oper, "front") == 0) printf("%d\n", front());

		else if(strcmp(oper, "back") == 0) printf("%d\n", back());

		else printf("Not allocated operator\n");
	}
	return 0;
}
