#include <stdio.h>

#define ABS(X) ((X) > 0? (X): (-X))
#define MIN(X, Y) ((X) > (Y)? (Y): (X))

int main(){
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", MIN(MIN(ABS((x-w)), ABS((y-h))), MIN(ABS((0-x)), ABS((0-y)))));

	return 0;
}
