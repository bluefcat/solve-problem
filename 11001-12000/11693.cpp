#include <cstdio>
#include <unordered_map>

using lint = long long;
constexpr lint M = 1'000'000'007;
#include <cstdlib>

using l128 = __int128;
using ulint = unsigned long long;

inline l128 abs(l128 x){
    return (x >= 0)?x:-x;
}

l128 mpow(l128 base, l128 exp, l128 mod){
    base %= mod;
	l128 result = 1;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return result;
}

ulint mgcd(ulint a, ulint b){
    if(a < b){
        ulint tmp = a; a = b; b = tmp;
    }
    while(b != 0){
        ulint r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool rabin(ulint p, ulint x){
	ulint d = x-1;
	while(true){
		l128 k = mpow(p, d, x);
		if(d & 1) return (k == 1 || k == x-1);
		if(k == x-1) return true;
		d >>= 1;
	}
}

bool is_prime(ulint x){
	ulint p[] = {
		2, 3, 5, 7, 11, 13, 17, 19 ,23, 29, 31, 37
	};
	for(int i = 0; i < 12; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 12; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}

ulint pollard_rho(l128 n){
	if(n % 2 == 0) return 2;
	if(is_prime(n)) return n;
	l128 x = rand()%(n-2)+2;
	l128 y = x;
	l128 c = rand() % 10 + 1;
	l128 g = 1;
	while(g == 1){
		x = (x*x%n+c)%n;
		y = (y*y%n+c)%n;
		y = (y*y%n+c)%n;

		g = mgcd(abs(x-y), n);
		if(g == n) return pollard_rho(n);
	}
	if(is_prime(g)) return g;
	else return pollard_rho(g);
}

lint S(lint p, lint e){
	lint x = (lint)((mpow(p, (e+1)%M, M) - 1) % M);
	lint y = (lint)(mpow((p - 1), M-2,  M));
	return (x * y) % M;
}

int main(){
	std::unordered_map<lint, lint> p{};
	lint n, m, result = 1;
	scanf("%lld %lld", &n, &m);

	while(n != 1){
		lint x = (lint)pollard_rho(n);
		p[x] += 1;
		n /= x;
	}
	
	for(auto& [x, e]: p){
		result = (result * S(x, (e*m)%M)) % M;
	}

	printf("%lld\n", result);

	return 0;
}
