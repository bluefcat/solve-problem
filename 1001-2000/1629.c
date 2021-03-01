#include <stdio.h>

long long mypow(long long x, long long y, long long m){
	int result = 1;

	while(1){
		if(y&1) result = (result*x)%m;
		y >>= 1;
		if(!y) break;
		x = (x*x)%m;
	}

	return result;
}

int main(){
	long long result = 1;
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld\n", mypow(a, b, c));

	return 0;
}
