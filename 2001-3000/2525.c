#include <stdio.h>
#define ABS(X) (((X) > 0)? (X): -(X))

int main(){
	int h, m, c;

	scanf("%d %d", &h, &m);
	scanf("%d", &c);

	h += c / 60; m += c % 60;
	h += m / 60; m %= 60;
	h %= 24;

	printf("%d %d", h, m);

	return 0;
}
