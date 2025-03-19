#include <cstdio>

using lint = long long;

constexpr lint MOD = 1000000000 + 7;
constexpr lint M = 200001;

lint mpow(lint x, lint e, lint m){
	x %= m;
	lint result = 1;
	while(e){
		if(e & 1) result = (result * x) % m;
		x = (x * x) % m;
		e >>= 1;
	}
	return result;
}

int main(){
	lint n, m, nume = 0, deno = 1;
	char x[M] = { 0, };
	
	scanf("%lld %lld", &n, &m);
	scanf("%s", x);
	
	if(n == 1){
		lint place = 1;
		lint result = 0;
		for(int i = 0; i < m; i ++){
			result = (result + (x[m-1-i] == '1') * place) % MOD;
			place = (place << 1) % MOD;
		}
		printf("%lld\n", result);
		return 0;
	}

	lint place = 1;
	lint count = mpow(2, n-1, MOD);
	count = mpow(count, m-1, MOD);

	lint tp = ((n % MOD) * mpow(2, n-2, MOD)) % MOD; //sum r * (n r)

	for(int i = 0; i < m; i ++){
		lint tmp = (count * tp) % MOD;
		nume += (tmp * place) % MOD;
		place = (place << 1) % MOD;
	}
	deno = mpow(2, (n-1), MOD);
	deno = mpow(deno, m, MOD);
	
	lint result = ((nume % MOD) * mpow(deno, MOD-2, MOD)) % MOD;
	printf("%lld\n", result);
	return 0;
}
