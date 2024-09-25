#include <cstdio>

using lint = long long;
constexpr int N = 4000001;
constexpr int MOD = 1000000007;

lint cache[N] = { 0, };

lint mpow(lint x, lint e){
	lint result = 1;
	while(e){
		if(e & 1) result = (result * x) % MOD;
		x = (x * x) % MOD;
		e >>= 1;
	}
	return result;
}

int main(){
	int m;
	scanf("%d", &m);
	cache[0] = 1; cache[1] = 1;
	for(int i = 2; i < N; i ++){
		cache[i] = (i * cache[i-1]) % MOD;
	}

	for(int i = 0; i < m; i ++){
		lint n, k;
		scanf("%lld %lld", &n, &k);
		lint rk = mpow(cache[k], MOD-2);
		lint rnk = mpow(cache[n-k], MOD-2);
		printf("%lld\n", ((cache[n]*rk%MOD)*rnk)%MOD);	

	}
	return 0;
}
