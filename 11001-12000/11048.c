#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[1001][1001];
int cache[1001][1001];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m; j ++) scanf("%d", map[i]+j);
	}

	cache[0][0] = map[0][0];

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cache[i][j] = map[i][j];

			if(i-1 >= 0) cache[i][j] = MAX(cache[i][j], (cache[i-1][j] + map[i][j]));
			if(j-1 >= 0) cache[i][j] = MAX(cache[i][j], (cache[i][j-1] + map[i][j]));
			if(i-1 >= 0 && j-1 >= 0) cache[i][j] = MAX(cache[i][j], (cache[i-1][j-1] + map[i][j]));
		}
	}

	printf("%d\n", cache[n-1][m-1]);

	return 0;
}
