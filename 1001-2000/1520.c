#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[501][501];
int cache[501][501];

int m, n;

int dx[] = { 0,  1,  0, -1 };
int dy[] = { 1,  0, -1,  0 };

int solution(int x, int y){
	int k = 0;

	if(x == m-1 && y == n-1) return 1;

	else if(cache[x][y] == -1){
		cache[x][y] = 0;

		for(int i = 0; i < 4; i ++){
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if(nx < 0 || m <= nx) continue;
			if(ny < 0 || n <= ny) continue;

			if(map[x][y] > map[nx][ny]) cache[x][y] += solution(nx, ny);
		}
	}

	return cache[x][y];
}

int main(){
	scanf("%d %d", &m, &n);

	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			cache[i][j] = -1;
			scanf("%d", map[i]+j);
		}
	}

	printf("%d\n", solution(0, 0));

	return 0;
}
