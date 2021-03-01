#include <stdio.h>

long long matrixA[5][5];
long long matrixB[5][5];

void product_matrix(int n, long long (*x)[5], long long (*y)[5], long long (*r)[5]){
    long long tmpA[5][5];
    long long tmpB[5][5];

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
            r[i][j] %= 1000000007;
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
    long long n;
    scanf("%lld", &n);

    matrixA[0][0] = 1; matrixA[0][1] = 1;
    matrixA[1][0] = 1; matrixA[1][1] = 0;

    matrixB[0][0] = 0; matrixB[0][1] = 1;
    matrixB[1][0] = 1; matrixB[1][1] = 0;


    pow_matrix(2, n);
    printf("%lld\n", matrixB[0][0]);

    return 0;
}