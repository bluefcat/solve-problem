#include <stdio.h>

#define QSIZE 102
int stack[QSIZE];
int top;

int number[102];
int result[102];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	int n, length = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i ++)
		scanf("%d", number+i);

	for(int i = 1; i <= n; i ++){
		int visited[102] = { 0, };
		int cand[102] = { 0, };
		int idx = 0;
		
		cand[idx++] = i;
		stack[top++] = i;

		while(top > 0){
			int cur = stack[--top];
			if(visited[cur] == 0){
				visited[cur] = 1;
				cand[idx++] = cur;
				stack[top++] = number[cur];
			}
			else{
				if(i == cur) result[length++] = i;
			}


		}
	}

	printf(">%d\n", length);
	for(int i = 0; i < length; i ++) printf("%d\n", result[i]);

	return 0;
}
