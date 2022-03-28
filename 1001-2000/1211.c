#include <stdio.h>

int product_digit(int x){
	int result = 1;
	while(x){
		result *= x % 10;
		x /= 10;
	}

	return result;
}

int product_self(int x){
	return x * product_digit(x);
}

int main(){
	int a, b;

	scanf("%d %d", &a, &b);



	printf("%d %d\n", product_self(a), product_self(b));

	return 0;
}
