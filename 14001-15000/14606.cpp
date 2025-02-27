#include <cstdio>
#include <algorithm>
constexpr int N = 11;
unsigned long long dp[N] = { 0, };

int main(){
	int n;
	scanf("%d", &n);
	dp[1] = 0;

	for(int i = 2; i < N; i ++){
		for(int j = 1; (i / 2) - j >= 0; j ++){
			dp[i] = std::max(
				dp[i], (i-j) * j + dp[i-j] + dp[j] 
			);
		}
	}

	printf("%lld\n", dp[n]);

	return 0;
}
