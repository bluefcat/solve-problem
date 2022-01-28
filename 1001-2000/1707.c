#include <stdio.h>

#define QSIZE 200001

int queue[QSIZE][2];
int head, tail;

int vertex[20001];

int main(){
	int k;
	scanf("%d", &k);

	for(int i = 0; i < k; i ++){
		int v, e;
		scanf("%d %d", &v, &e);

		head = tail;
		tail = head;
		for(int j = 0; j < v; j ++) vertex[j] = 0;
		
		for(int j = 0; j < e; j ++){
			int x, y;
			scanf("%d %d", &x, &y);
			
			queue[tail][0] = x;
			queue[tail][1] = y;

			tail = (tail + 1) % QSIZE;
		}

	}

	return 0;
}
