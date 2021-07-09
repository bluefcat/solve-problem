#include <stdio.h>
#define ABS(X) (((X) > 0)? (X): -(X))

int graph[1001][1001];
int visited[1001];

void DFS(int s, int n){
	printf("%d ", s);
	visited[s] = 1;

	for(int i = 0; i <= n; i ++){
		if((graph[s][i] == 1) && (visited[i] == 0)){
			DFS(i, n);
		}
	}
	
	return ;
}

void BFS(int s, int n){
	int q[1001] = { 0, };
	int head = 0;
	int tail = 0;

	q[tail] = s;
	tail = (tail+1) % 1001;
	visited[s] = 1;
	printf("%d ", s);

	while(ABS(tail-head) > 0){
		int cur = q[head];
		head = (head+1) % 1001;
		
		for(int i = 0; i <= n; i ++){
			if((graph[cur][i] == 1) && (visited[i] == 0)){
				q[tail] = i;
				tail = (tail+1) % 1001;
				visited[i] = 1;
				printf("%d ", i);
			
			}
		}
	}		

	return ;
}

int main(){
	int n = 0, m = 0, s = 0;
	scanf("%d %d %d", &n, &m, &s);
	
	for(int i = 0; i < m; i ++){
		int f = 0, e = 0;
		scanf("%d %d", &f, &e);
		graph[f][e] = 1;
		graph[e][f] = 1;
	}

	DFS(s, n);
	printf("\n");

	for(int i = 0; i <= n; i ++) visited[i] = 0;
	BFS(s, n);
	printf("\n");

	return 0;
}
