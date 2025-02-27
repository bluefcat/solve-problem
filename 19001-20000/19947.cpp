#include <cstdio>
#include <algorithm>

constexpr int Y = 11;
unsigned long long dp[Y] = { 0, };


int main(){
	unsigned long long h, y;
	scanf("%lld %lld", &h, &y);
	
	dp[0] = h;

	for(int i = 1; i < Y; i ++){
		unsigned long long tmp[3] = { 0, };
		tmp[0] = dp[i-1] + dp[i-1]/20;
		if(i >= 3)
			tmp[1] = dp[i-3] + dp[i-3]/5;

		if(i >= 5)
			tmp[2] = dp[i-5] + (7*dp[i-5])/20;
		dp[i] = std::max({tmp[0], tmp[1], tmp[2]});
	}

	printf("%lld\n", dp[y]);
	
	return 0;
}
