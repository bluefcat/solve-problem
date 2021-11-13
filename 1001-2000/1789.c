#include <stdio.h>
#include <math.h>

int main(){
	int result = 0;
	unsigned long long n = 0;
	scanf("%lld", &n);

	result = (int)((sqrt(1+8*n) - 1) / 2);


	printf("%d\n", result);
	return 0;
}
