#include <cstdio>

constexpr int N = 81;

unsigned long long dp[N];

int main(){
	int n;
	scanf("%d", &n);
	
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i < N; i ++)
		dp[i] = dp[i-2] + dp[i-1];

	printf("%lld\n", dp[n-1]*2+dp[n]*2);

	return 0;
}
