#include <cstdio>

constexpr int N = 101;

int g[N][N] = { 0, };

int main(){
	
	for(int dist = 0; dist < N; dist ++){
		for(int x = dist; x >= 0; x --){
			bool check[N*N] = { false, };
			int y = dist - x;

			for(int xk = 0; xk < x; xk ++)
				check[g[xk][y]] = true;
			
			for(int yk = 0; yk < y; yk ++)
				check[g[x][yk]] = true;
			
			int xk = 0, yk = 0;
			while(xk < x && yk < y){
				check[g[xk][yk]] = true;
				xk ++; yk ++;
			}

			for(int i = 0; i < N*N; i ++){
				if(check[i] == false){
					g[x][y] = i;
					break;
				}
			}
		}
	}
	
	for(int _ = 0; _ < 5; _ ++){
		int n, result = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			int x, y;
			scanf("%d %d", &x, &y);
			result ^= g[x][y];
		}
		printf("%d\n", result);
	}



	return 0;
}
