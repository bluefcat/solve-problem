#include <stdio.h>
#include <stdlib.h>
#define QSIZE 100001
int queue[QSIZE];
int head, tail;

typedef struct vector_{
	int d;
	struct vector_ * n;
} vector;

int result[100001];
int size[100001];
vector* map[100001];


int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n-1; i ++){
		int x, y;
		x = 1; y = i + 2;
		//scanf("%d %d", &x, &y);

		vector* ix = map[x]; size[x] ++;
		for(ix; ix->n; ix = ix->n);
		
		ix->n = (vector*)malloc(sizeof(vector));
		ix->n->d = y;


		vector* iy = map[y]; size[y] ++;
		for(iy; iy->n; iy = iy->n);
		
		iy->n = (vector*)malloc(sizeof(vector));
		iy->n->d = x;
	}

	queue[tail] = 1;
	tail = (tail + 1) % QSIZE;

	while(head != tail){
		int cur = queue[head];
		head = (head + 1) % QSIZE;

		for(vector* in = map[cur]; in->n; in = in->n){
			int n = in->d;

			if(n && result[n] == 0){
				result[n] = cur;

				queue[tail] = n;
				tail = (tail + 1) % QSIZE;
			}
		}
	}

	for(int i = 2; i <= n; i ++){
		printf("%d\n", result[i]);
	}

	return 0;
}
