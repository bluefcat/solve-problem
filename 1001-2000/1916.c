#include <stdio.h>

#define INF -1
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
int cache[1001][1001];
int cost[1001];
int visited[1001];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i ++) 
		for(int j = 0; j < n; j ++)
			cache[i][j] = i==j? 0: INF;
	
	for(int i = 0; i < m; i ++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		cache[u][v] = w;
	}

	int start, end;
	scanf("%d %d", &start, &end);
	
	for(int i = 0; i < n; i ++) cost[i] = cache[start][i];
	visited[start] = 1;

	for(int p = 0; p < n-2; p ++){
		int idx = 0;
		int min = INF;
		for(int i = 1; i <= n; i ++){
			if(cost[i] == INF) continue;
			if(min == INF || (min > cost[i] && !visited[idx])){
				idx = i;
				min = cost[i];
			}
		}

		visited[idx] = 1;
		for(int i = 1; i <= n; i ++){
			if(!visited[idx] && cache[idx][i] != INF){
				if(cost[idx] + cache[idx][i] < cost[i]){
					cost[i] = cost[idx] + cache[idx][i];
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		printf("%d\t", cost[i]);
	}
	
}
