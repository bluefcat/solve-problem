#include <stdio.h>
#include <limits.h>
#define MAXLEN 501
#define MIN(X, Y) ((X) > (Y)? (Y): (X))

unsigned int matrix[MAXLEN][2];
unsigned int cache[MAXLEN][MAXLEN];

int main(){
	
	unsigned int tmp; 
	int n = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%u %u", matrix[i], matrix[i]+1);
		cache[i][i] = matrix[i][0] * matrix[i][1];
	}

	for(int x = 1; x <= n; x ++){
		for(int d = 1; d < x; d ++){
			int y = x - d;
			cache[x][y] = INT_MAX;
			
			int t = d+1;
			for(int i = 1; i <= d; i ++){
				unsigned int tmp = cache[x-i][y] * matrix[y+(t-i)][1];
				
				cache[x][y] = MIN(tmp, cache[x][y]);
			}
		}
	}

	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= n; j ++) printf("%10u\t", cache[i][j]);
		printf("\n");
	}
	
	

	return 0;
}
