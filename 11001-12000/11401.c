#include <stdio.h>

#define N 1000000007
#define M 4000001

long long fact(int n){
	long long result = 1;

	for(int i = 0; i < n; i ++){
		result *= (i+1);
		result %= N;
	}
	
	return result % N;
}

long long mpow(long long n, long long k){
	if(k == 0) return 1;
	if(k & 1 == 1) return (mpow(n, k-1) * n) % N;

	long long h = mpow(n, k / 2) % N;
	
	return (h * h) % N; 
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	long long a = fact(n) % N;
	long long b = fact(k) * fact(n-k) % N;
	b = mpow(b, N-2) % N;

	long long r = (a * b) % N;

	printf("%lld\n", r);

	return 0;
}
