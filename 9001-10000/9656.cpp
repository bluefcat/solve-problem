#include <cstdio>
#include <algorithm>

constexpr int N = 1001;

int dp[N] = { 0, };

int main(){
	int n;
	scanf("%d", &n);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	
	for(int i = 4; i < N; i ++){
		dp[i] = (dp[i-1] == 0 || dp[i-3] == 0);
	}

	if(dp[n] == 1){
		printf("SK\n");
		return 0;
	}
	printf("CY\n");

	return 0;
}
