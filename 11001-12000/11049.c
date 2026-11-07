#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 501
#define MIN(X, Y) ((X) > (Y)? (Y): (X))

int main(){
	int n;
	unsigned int matrix[MAXLEN][2];
	unsigned int cache[MAXLEN][MAXLEN];
	
	memset(matrix, 0, sizeof(matrix));
	memset(cache, 0, sizeof(cache));
	
	scanf("%d", &n);

	for(int i = 0 ; i < n; i ++) scanf("%d %d", matrix[i] + 0, matrix[i] + 1);
	
	for(int i = 0; i < n; i ++)
		for(int j = 0; i + j < n; j ++){
			cache[i][i+j] = INT_MAX;
			for(int m = i; m < i + j; m ++){
				unsigned int count = matrix[i][0] * matrix[m][1] * matrix[j][1];
				cache[i][j] = MIN(cache[i][j], cache[i][m] + cache[m+1][j] + count);
			}
		}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) printf("%d ", cache[i][j]);
		printf("\n");
	}
	printf("%d\n", cache[0][n-1]); 
	return 0;
}
