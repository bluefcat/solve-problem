#include <stdio.h>
#include <limits.h>

#define MIN(X, Y) ((X) > (Y)? (Y): (X))

int cache[501][501];
int cost[501];
int sum[501];

int main(){
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t ++){
		//input cost
		int k = 0;
		scanf("%d", &k);
		
		for(int i = 1; i <= k; i ++){
			scanf("%d", cost+i);
			sum[i] = sum[i-1] + cost[i];
		}

		for(int i = 1; i < k; i ++){
			for(int x = 1; x + i <= k; x ++){
				int y = x + i;
				
				cache[x][y] = INT_MAX;

				for(int m = x; m < y; m ++){
					cache[x][y] = MIN(cache[x][y], (cache[x][m] + cache[m+1][y] + sum[y] - sum[x-1]));
				}

			}
		}

		printf("%d\n", cache[1][k]);
	}

	return 0;
}
