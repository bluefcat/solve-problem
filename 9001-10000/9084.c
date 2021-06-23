#include <stdio.h>

#define MAXCOIN 21
#define MAXMONEY 10001

int coins[MAXCOIN];
int cache[MAXCOIN][MAXMONEY];

int main(){
	int T;
	scanf("%d", &T);
	
	for(int t = 0; t < T; t ++){
		int N, M;

		scanf("%d", &N);
		for(int i = 1; i <= N; i ++){
			scanf("%d", coins+i);
		}

		scanf("%d", &M);
		
		for(int i = 1; i <= N; i ++){
			int coin = coins[i];
			for(int j = 0; j <= M; j ++){
				if(coin == j){
					cache[i][j] = cache[i-1][j] + 1;
				}
				else if(coin > j){
					cache[i][j] = cache[i-1][j]; 
				}
				else{
					cache[i][j] = cache[i-1][j] + cache[i][j-coin];
				}
			}

		}
		
		printf("%d\n", cache[N][M]);
	}

	return 0;
}
