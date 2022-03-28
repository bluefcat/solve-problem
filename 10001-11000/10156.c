#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))?(X): (Y))

int main(){
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	printf("%d\n", MAX(0, x*y-z));

	return 0;
}
