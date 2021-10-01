#include <stdio.h>
#define MAX(X, Y) ((X) > (Y)? (X): (Y))
int cache[16][16];
int schedule[16][2];

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d %d", schedule[i+1], schedule[i+1]+1);
	}

	for(int d = 1; d <= n; d ++){
		for(int i = 1; i <= n; i ++){
			int t = schedule[i][0];
			int p = schedule[i][1];

			if(i+t-1 > d) continue;
			cache[d][i+t-1] = MAX(p, cache[d-1][i+t-1]); 
			result = MAX(result, cache[d][i+t-1]);

		}
	}

	for(int i = 0; i <= n; i ++){
		printf("[%d] ", i);
		for(int j = 0; j <= n; j ++)
			printf("(%d, %d)", j, cache[i][j]);
		printf("\n");
	}
	printf("%d\n", result);


	return 0;
}
