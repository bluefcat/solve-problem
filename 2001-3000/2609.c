#include <stdio.h>

void max_swap(int* x, int* y){
	if(*x > *y) return;
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return ;
}

int gcd(int x, int y){
	
	return (x%y)? gcd(y, x%y): y;
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	
	max_swap(&x, &y);

	printf("%d\n%d\n", gcd(x, y), x*y/gcd(x, y));
	return 0;
}
