#include <stdio.h>

int matrixA[100][100];
int matrixB[100][100];
int matrixC[100][100];

int main(){
	int n, m, k;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			scanf("%d", matrixA[i]+j);
		}
	}

	scanf("%d %d", &m, &k);
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < k; j ++){
			scanf("%d", matrixB[i]+j);
		}
	}

	for(int p = 0; p < n; p ++){
		for(int q = 0; q < k; q ++){
			for(int r = 0; r < m; r ++){
				matrixC[p][q] += matrixA[p][r]*matrixB[r][q];
			}
		}
	}	
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < k; j ++){
			printf("%d ", matrixC[i][j]);
		}
		printf("\n");
	}

	return 0;
}
