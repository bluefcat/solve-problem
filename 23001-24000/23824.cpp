#include <cstdio>

using lint = long long;

constexpr lint MOD = 1048573;

lint fact[MOD+2] = { 1, };

void prefact(){
	for(int i = 1; i < MOD+2; i ++){
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

lint mpow(lint x, lint e, lint m){
	lint result = 1;
	while(e){
		if(e & 1) result = (result * x) % m;
		x = (x * x) % m;
		e >>= 1;
	}
	return result % m;
}

lint mcomb(lint n, lint m, lint mod){
	lint result = 1;
	while(n | m){
		lint n_ = n % mod;
		lint m_ = m % mod;

		if(m_ > n_) return 0;

		result = (result * fact[n_]) % mod;
		result = (result * mpow(fact[n_ - m_], mod-2, mod)) % mod;
		result = (result * mpow(fact[m_], mod - 2, mod)) % mod; 

		n /= mod;
		m /= mod;
	}
	return result;
}


int main(){
	prefact();

	lint k, a, n;
	scanf("%lld %lld %lld", &k, &a, &n);

	lint target = n;
	lint place = 0;
	
	return 0;
}

