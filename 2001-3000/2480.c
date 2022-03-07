#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int main(){
	int a, b, c, result = 0;
	scanf("%d %d %d", &a, &b, &c);

	if(a == b && b == c){
		result = 10000 + a * 1000;
	}
	else if(a == b || a == c){
		result = 1000 + a * 100;
	}
	else if(b == c){
		result = 1000 + b * 100;
	}
	else{
		result = MAX(MAX(a, b), c) * 100;
	}

	printf("%d\n", result);

	return 0;
}
