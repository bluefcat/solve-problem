#include <cstdio>
#include <cmath>
#include <climits>

constexpr int N = 57;

int main(){
	int W, H, K;
	bool board[N][N] = { 0, };
	int cache[2][N][N] = { 0, };
	scanf("%d %d %d", &H, &W, &K);
	
	for(int i = 0; i < H; i ++){
		for(int j = 0; j < W; j ++){
			char x;
			scanf("\n%c", &x);
			board[i][j] = (x == 'B');
		}
	}

	for(int c = 0; c <= 1; c ++){
		int b = c;
		for(int i = 0; i < H; i ++){
			for(int j = 0; j < W; j ++){
				b ^= true;
				cache[c][i+1][j+1] += std::abs(b - board[i][j]);
			}
			if(!(W % 2)) b ^= true;
		}
	}	

	for(int c = 0; c <= 1; c ++){
		for(int i = 0; i < H+1; i ++){
			for(int j = 0; j < W+1; j ++){
				cache[c][i][j] += cache[c][i][j-1];
			}
		}
		for(int i = 0; i < H+1; i ++){
			for(int j = 0; j < W+1; j ++){
				cache[c][i][j] += cache[c][i-1][j];
			}
		}
	}


	int result = INT_MAX;
	for(int c = 0; c <= 1; c ++){
		for(int i = K; i < H+1; i ++){
			for(int j = K; j < W+1; j ++){
				result = std::min(
					result,
					cache[c][i][j] - 
					(cache[c][i][j-K] + cache[c][i-K][j] - cache[c][i-K][j-K])
				);
			}
		}
	}


	printf("%d\n", result);

	return 0;
};
