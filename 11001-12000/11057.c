#include <stdio.h>

int cache[1001][10];

int main(){
	int n, result = 0;
	scanf("%d", &n);
	
	//init
	for(int i = 0; i < 10; i ++) cache[1][i] = 1;

	for(int i = 2; i <= n; i ++){
		for(int j = 0; j < 10; j ++){
			for(int k = 0; k <= j; k ++){
				cache[i][j] += cache[i-1][k] % 10007;
			}
		}
	}
	
	for(int i = 0; i < 10; i ++){
		result += cache[n][i] % 10007;
	}

	printf("%d\n", result % 10007);

	return 0;
}
