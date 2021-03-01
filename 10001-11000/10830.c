#include <stdio.h>

int matrixA[5][5];
int matrixB[5][5];

void product_matrix(int n, int (*x)[5], int (*y)[5], int (*r)[5]){
    int tmpA[5][5];
    int tmpB[5][5];

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            tmpA[i][j] = x[i][j];
            tmpB[i][j] = y[i][j];
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            r[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			for(int k = 0; k < n; k ++){
				r[i][j] += tmpA[i][k]*tmpB[k][j];
			}
            r[i][j] %= 1000;
		}
	}	
}

void pow_matrix(int n, long long y){
    while(1){
        if(y&1) product_matrix(n, matrixA, matrixB, matrixB);
        y >>= 1;
        if(!y) break;
        product_matrix(n, matrixA, matrixA, matrixA);
    }
}

int main(){
    int n; long long b;
    scanf("%d %lld", &n, &b);

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            scanf("%d", matrixA[i]+j);
            if(i == j) matrixB[i][j] = 1;
        }
    }

    pow_matrix(n, b);

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    return 0;
}