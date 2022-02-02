#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int main(){
	int a, b, result = 0;
	int tmp = 0;
	while(scanf("%d %d", &a, &b) && b != 0){
		tmp += b - a;

		result = MAX(result, tmp);
	}

	printf("%d\n", result);

	return 0;
}
