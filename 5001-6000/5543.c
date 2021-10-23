#include <stdio.h>

#define MIN(X, Y) ((X) > (Y)? (Y): (X))

int main(){
	int x, y, z, a, b;
	scanf("%d %d %d %d %d", &x, &y, &z, &a, &b);
	
	int t = MIN(x, MIN(y, z));
	int p = MIN(a, b);

	printf("%d\n", t+p-50);
	return 0;
}
