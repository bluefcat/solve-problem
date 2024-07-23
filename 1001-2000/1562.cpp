#include <cstdio>

using ll = long long;

constexpr int N = 101;
constexpr ll MOD = 1000000000;
int main(){
	int n;
	ll cache[N][1<<10][10] = { 0, };
	
	scanf("%d", &n);
	
	for(int i = 1; i <= 9; i ++){
		cache[1][1<<i][i] = 1;
	}

	for(int i = 2; i <= n; i ++){
		for(int p = 0; p < (1 << 10); p ++){
			cache[i][(1<<0)|p][0] += cache[i-1][p][1];
			cache[i][(1<<9)|p][9] += cache[i-1][p][8];
			for(int q = 1; q <= 8; q++){
				ll tmp = (cache[i-1][p][q-1] + cache[i-1][p][q+1]) % MOD;
				cache[i][(1<<q)|p][q] = (cache[i][(1<<q)|p][q] + tmp) % MOD;
			}
		}	
	}
	ll result = 0;
	for(int i = 0; i < 10; i ++){
		result = (result + cache[n][0b1111111111][i]) % MOD;
	}
	printf("%lld\n", result);

	return 0;
}
