#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int main(){
	int cache[1001] = { 0, };

	int result = 0;
	int a, b, c;
	int n;
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &n);

	for(int i = 0; i < 3*n; i ++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		cache[(int)(i/3)] += a*x+b*y+c*z;
	}

	for(int i = 0; i < n; i ++){
		result = MAX(result, cache[i]);
	}

	printf("%d\n", result);

	return 0;
}
