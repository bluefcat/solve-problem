#include <stdio.h>

#define COUNT_MAX 101
#define WEIGHT_MAX 100001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int v[COUNT_MAX];
int w[COUNT_MAX];

int dp[COUNT_MAX][WEIGHT_MAX];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i ++){
		scanf("%d %d", w+i+1, v+i+1);
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			if(j >= w[i]) dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}

	printf("%d\n", dp[n][k]);

	return 0;
}
