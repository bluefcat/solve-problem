#include <cstdio>

using lint = long long;
constexpr int MOD = 1000000007;

lint fact(lint x){
	lint result = 1;
	while(x){
		result = (result * x) % MOD;
		x --;
	}
	return result;
}

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

	for(int i = 0; i < m; i ++){
		lint n, k;
		scanf("%lld %lld", &n, &k);
		lint rk = mpow(fact(k), MOD-2);
		lint rnk = mpow(fact(n-k), MOD-2);
		printf("%lld\n", ((fact(n)*rk)%MOD)*rnk%MOD);	

	}
	return 0;
}
