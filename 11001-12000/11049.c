#include <stdio.h>
#include <limits.h>
#define MAXLEN 501
#define MIN(X, Y) ((X) > (Y)? (Y): (X))

unsigned int matrix[MAXLEN];
unsigned int product[MAXLEN];

int main(){
	unsigned int N, result = UINT_MAX;
	scanf("%d", &N);

	for(int n = 0; n < N; n ++){
		scanf("%d %d", matrix+n, matrix+n+1);

	}

	product[0] = 0;
	//product make
	for(int i = 1; i < N; i ++){
		product[i] = product[i-1] + matrix[i] * matrix[i+1];
	}

	for(int c = 1; c < N; c ++){
		int l = matrix[0] * (product[c-1] + matrix[c] * matrix[N]);
		int r = matrix[c] * (product[N-1] - product[c]);
		
		result = MIN(result, (l+r));
	}

	printf("%d\n", result);

	return 0;
}
