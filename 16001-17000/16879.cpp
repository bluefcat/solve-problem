#include <cstdio>

constexpr int N = 30;
int g[N][N] = { 0, };

int main(){
	for(int d = 1; d < N; d ++){
		for(int i = 0; i <= d; i ++){
			bool check[N*N] = { false, };

			for(int x = 0; x < i; x ++)
				check[g[x][d-i]] = true;

			for(int y = 0; y < d-i; y++)
				check[g[i][y]] = true;
			if(i-1 >= 0 && d-i-1 >= 0)
				check[g[i-1][d-i-1]] = true;

			for(int k = 0; k < N*N; k ++){
				if(check[k] == false){
					g[i][d-i] = k;
					break;
				}
			}
		}
	}

	for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 20; j ++){
			printf("[%3d]", g[i][j]);
		}
		printf("\n");
	}


	return 0;
}
