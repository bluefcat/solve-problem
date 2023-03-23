#include <stdio.h>

long long result[10];

int main(){
	long long n;
	scanf("%lld", &n);
	
	long long x = n;
	long long x1, x2;
	
	while(x){
		x1 = x % 10;
		x /= 10;
		x2 = x % 10;
		
		

		printf("%lld %lld\n", x2, x1);
	}

	for(int i = 0; i < 10; i ++){
		printf("%lld ", result[i]);
	}
	printf("\n");

	return 0;
}
