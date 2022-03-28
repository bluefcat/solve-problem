#include <stdio.h>

long long n;
long long p;

long long famod(long long n, long long p){

	long long result = 1;

	long long s = 1;
	long long e = n;

	while(s < e){
		result *= (s*e)%p;
		result %= p;
		s ++; e --;
	}

	if(s == e) result = (result * s) % p;

	return result;
}

int main(){
	scanf("%lld %lld", &n, &p);
	
	printf("%lld\n", famod(n, p));

	return 0;
}
