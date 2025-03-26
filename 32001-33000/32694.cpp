#include <cstdio>

using lint = long long;

constexpr lint MOD = 1234543;

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

int main(){
	prefact();

	int Q;
	scanf("%d\n", &Q);
	while(Q--){
		lint w, b;
		scanf("%lld %lld", &w, &b);
		
		lint result = 1;
		
		lint n = w+b-1, m = b;
		while(n > 0 && m > 0){
			lint nm = n % MOD, mm = m % MOD;
			if(mm < 0){
				result = 0;
				break;
			}
			result = (
				((((result * fact[n % MOD]) % MOD) * 
				mpow(fact[((n % MOD)-(m % MOD)) % MOD], MOD-2, MOD)) % MOD) *
				mpow(fact[m % MOD], MOD-2, MOD)
			)%MOD;	
			n /= MOD;
			m /= MOD;
		}

		if(b & 1){
			printf("odd %lld\n", result);
		}
		else{
			printf("even %lld\n", result);
		}

	}
	return 0;
}

