#include <cstdio>
#include <algorithm>

constexpr int N = 200001;
long long arr[N];
long long dp[N];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);
	
	dp[0] = arr[0];
	long long answer = arr[0]-dp[0];
	for(int i = 1; i < N; i ++){
		dp[i] = std::min(dp[i-1], arr[i]);	
		answer = std::max(answer, arr[i] - dp[i]);
	}

	printf("%lld\n", answer);

	return 0;

}
