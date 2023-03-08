#include <stdio.h>

unsigned long long re_count = 0;
unsigned long long dp_count = 0;

int re_fib(int n){
	if(n == 1 || n == 2){
		re_count ++;
		return 1;
	}
	return re_fib(n-1) + re_fib(n-2);
}

int dp_fib(int n){
	int f[41] = { 0, };
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= n; i ++){
		dp_count ++;
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}


int main(){
	int n;
	scanf("%d", &n);
	re_fib(n);
	dp_fib(n);
	printf("%lld %lld\n", re_count, dp_count);
	return 0;
}
