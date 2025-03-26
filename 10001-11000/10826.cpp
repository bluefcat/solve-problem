#include <cstdio>

constexpr int N = 10001;
unsigned long long dp[N];

int main(){
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i < N; i ++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	printf("%lld\n", dp[n]);
	return 0;
}
