#include <stdio.h>

#define SIZE 100001

char queue[SIZE];
int head, tail;

char stack[SIZE];
int top;

int main(){
	char string[SIZE] = { 0, };
	char result[SIZE] = { 0, };
	int idx = 0;

scanf("%[^\n]s", string);
	
	char* p = string;
	//bracket close = 0
	//bracket open = 1
	//space = 2
	int mode = 0;
	int f = 0;
	while(*p){
START:
		f = 0;
		switch(*p){
			case '<':
				mode = 1;
				p ++;
				goto START;

			case '>':
				mode = 0;
				p ++;
				if(head != tail){
					result[idx++] = '<'; f = 1;
				}
				while(head != tail){
					result[idx++] = queue[head];
					head = (head + 1) % SIZE;
				}
				if(f){
					result[idx++] = '>'; f = 0;
				}
				goto START;
			case ' ':
				if(mode == 0) mode = 2;
				break;
		}

		f = 0;
		switch(mode){
			case 0:
				stack[top++] = *p;
				
				if(head != tail){
					result[idx++] = '<'; f = 1;
				}
				while(head != tail){
					result[idx++] = queue[head];
					head = (head + 1) % SIZE;
				}
				if(f){
					result[idx++] = '>'; f = 0;
				}

				break;
			case 1:
				queue[tail] = *p;
				tail = (tail + 1) % SIZE;

				for(top; top >= 1; top --) result[idx++] = stack[top-1];
				break;
			case 2:
				for(top; top >= 1; top --) result[idx++] = stack[top-1];
				result[idx++] = ' ';
				mode = 0;
				break;
		}

		p ++;
	}

	for(top; top >= 1; top --) result[idx++] = stack[top-1];

	printf("%s\n", result);

	return 0;
}
