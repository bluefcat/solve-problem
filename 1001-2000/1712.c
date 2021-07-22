#include <stdio.h>

int main(){
	int a = 0, b = 0, c = 0;
	int result = -1;

	scanf("%d %d %d", &a, &b, &c);
	
	result = (b >= c)?-1:(a/(c-b)+1);

	printf("%d\n", result);

	return 0;
}
