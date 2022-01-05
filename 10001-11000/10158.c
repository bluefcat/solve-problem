#include <stdio.h>
#define ABS(X) (((X) < 0)? -(X): (X))

int main(){

	int w, h;
	int x, y;
	unsigned int t;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%u", &t);
	
	x = (x+t) % (w<<1);
	y = (y+t) % (h<<1);
	x = w-ABS((w-x));
	y = h-ABS((h-y));

	printf("%d %d\n", x, y);

	return 0;
}
