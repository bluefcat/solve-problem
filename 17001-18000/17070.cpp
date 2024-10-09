#include <cstdio>

constexpr int N = 18;

int field[N][N];
int cache[N][N][3]; // 0: horizontal
					// 1: vertical
					// 2: diagonal

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) scanf("%d", field[i]+j);

	cache[1][2][0] = 1;
	
	for(int i = 1; i <= n; i ++){
		for(int j = 2; j <= n; j ++){
			if(field[i][j+1] == 0)
				cache[i][j+1][0] += cache[i][j][0] + cache[i][j][2];
			if(field[i+1][j] == 0)
				cache[i+1][j][1] += cache[i][j][1] + cache[i][j][2];
			if(field[i+1][j] == 0 && field[i][j+1] == 0 && field[i+1][j+1] == 0)
				cache[i+1][j+1][2] += cache[i][j][0] + cache[i][j][1] + cache[i][j][2];
		}
	}

	printf("%d\n", cache[n][n][0] + cache[n][n][1] + cache[n][n][2]);

	return 0;
}
