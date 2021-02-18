#include <stdio.h>
//pesano period
int main()
{
    long long int fib[3];
	fib[0] = 0; fib[1] = 1; fib[2] = 1;

	long long int n;
	scanf("%lld", &n);

	for (long long int i = 0; i <= n-2; i++) {
		fib[(i+2)%3] = fib[(i+1)%3] + fib[i%3];
        fib[(i+2)%3] %= 100;
        printf("%lld ", fib[(i+2)%3]);
        if(i%15 == 0) printf("\n");
	}
    printf("\n");
	//printf("%lld\n", fib[n%10000]);
	return 0;
}