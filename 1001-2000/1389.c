#include <stdio.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define INF 10000001

int graph[102][102];
int floyd[102][102];
int n, m;
int result;

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++) graph[i][j] = INF;
	}

	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1; graph[y][x] = 1;
	}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) floyd[i][j] = graph[i][j];

	for(int m = 1; m <= n; m ++){
		for(int s = 1; s <= n; s ++){
			for(int f = 1; f <= n; f++){
				floyd[s][f] = MIN(floyd[s][f], floyd[s][m] + floyd[m][f]);
			}
		}
	}

	int sum[101] = { 0, };
	for(int i = 1; i <= n; i ++){
		int tmp = 0;
		for(int j = 1; j <= n; j ++) if(i != j) tmp += floyd[i][j]; 
		sum[i] = tmp;
	}
	
	result = 1;
	for(int i = 2; i <= n; i ++){
		if(sum[result] > sum[i]) result = i;
	}

	printf("%d\n", result);
	return 0;
}
