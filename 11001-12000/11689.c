#include <stdio.h>

long mpow(long x, int y){
	if(y == 0) return 1;
	if(y == 1) return x;
	
	if(y & 1) return x * mpow(x, y-1);

	long half = mpow(x, y >> 1);

	return half * half;
}

int main(){
	long result = 1;
	long n;
	scanf("%ld", &n);

	long p = 2;

	while(n > 1){
		for(int i = 2; i < p; i ++){
			if(p % i == 0) goto NOPRIME;
		}
		
		int tmp = 0;
		
		while(n % p == 0){
			tmp ++;
			n /= p;
		}
		if(tmp != 0)
			result *= (mpow(p, tmp) - mpow(p, tmp-1));

		NOPRIME:
			p ++;
	}
	
	printf("%ld\n", result);
}
