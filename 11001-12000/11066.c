#include <stdio.h>
#define MIN(X, Y) ((X) > (Y)? (Y): (X))

int f(int* a, int x, int y, int n){
	if(n == 2) return a[x] + a[y];
	
	int result = f(a, x, x+1, n-1) + f(a, x+2, y, n-1);

	for(int i = x+2; i+1 <= y; i ++){
		result = MIN(result, (f(a, x, i, n-1) + f(a, i+1, y, n-1)));
	}

	return result;
}

int main(){
	int a[] = { 40, 30, 30, 50 };
	
	printf("%d\n", f(a, 0, 3, 4));


	return 0;
}
