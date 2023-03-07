#include <stdio.h>
#define LENGTH 60001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int sum(int n, int* x, int* y){
	int result = 0;
	
	for(int i = 0; i < n; i ++) result += x[i] * y[i];

	return result;
}

int main(){
	int result = 0;
	int n;
	int X[2*LENGTH] = { 0, };
	int Y[LENGTH] = { 0, };

	scanf("%d", &n);

	//input 
	for(int i = 0; i < n; i ++){
		scanf("%d", X + i);
		X[i+n] = X[i];
	}
	for(int i = n-1; i >= 0; i --) scanf("%d", Y + i);
	
	//calculate
	for(int i = 0; i < n; i ++) result = MAX(result, sum(n, X+i, Y));

	printf("%d\n", result);

	return 0;
}
