#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define QSIZE 100001

int queue[QSIZE][2];
int head, tail;

int visited[101];
int map[101][101];

int main(){
	int n, x, y;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);

	int m;
	scanf("%d", &m);

	for(int i = 0; i < m; i ++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}

	int result = -1;
	
	queue[tail][0] = x;
	queue[tail][1] = 0;
	tail = (tail + 1) % QSIZE;
	visited[x] = 1;

	while(head != tail){
		int cur = queue[head][0];
		int dist = queue[head][1];
		head = (head + 1) % QSIZE;
		
		for(int i = 1; i <= n; i ++){
			if(map[cur][i] && !visited[i]){
				queue[tail][0] = i;
				queue[tail][1] = dist+1;

				visited[i] = 1;

				tail = (tail + 1) % QSIZE;
				
				if(i == y) result = dist + 1;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
