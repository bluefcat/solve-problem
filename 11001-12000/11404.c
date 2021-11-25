#include <stdio.h>
#include <limits.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define INF INT_MAX

long cache[101][101];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++) cache[i][j] = INF;
	}

	for(int i = 0; i < m; i ++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		cache[u][v] = MIN(cache[u][v], w);
	}

	for(int m = 1; m <= n; m ++){
		for(int u = 1; u <= n; u ++){
			for(int v = 1; v <= n; v ++){
				cache[u][v] = MIN(cache[u][v], (cache[u][m] + cache[m][v]));
			}
		}
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(cache[i][j] == INF || i == j) printf("0 ");
			else printf("%d ", cache[i][j]);
		}
		printf("\n");
	}

}
