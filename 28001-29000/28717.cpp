#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_map>

using ll = __int128;
using ull = unsigned long long;
using std::unordered_map;

inline ll ABS(ll x){
    return (x >= 0)?x:-x;
}

ull pow(ll base, ll exp, ll mod){
    base %= mod;
	ll result = 1;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return (ull)result;
}

ull mGCD(ull a, ull b){
    if(a < b){
        ull tmp = a; a = b; b = tmp;
    }
    while(b != 0){
        ull r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool rabin(ull p, ull x){
	ull d = x-1;
	while(true){
		ll k = pow(p, d, x);
		if(d & 1) return (k == 1 || k == x-1);
		if(k == x-1) return true;
		d >>= 1;
	}
}

bool is_prime(ull x){
	ull p[] = {
		2, 7, 61
	};
	for(int i = 0; i < 3; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 3; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}


ull pollard_rho(ll n){
	if(n % 2 == 0) return 2;
	if(is_prime(n)) return n;
	ll x = rand()%(n-2)+2;
	ll y = x;
	ll c = rand() % 10 + 1;
	ll g = 1;
	while(g == 1){
		x = (x*x%n+c)%n;
		y = (y*y%n+c)%n;
		y = (y*y%n+c)%n;

		g = mGCD(ABS(x-y), n);
		if(g == n) return pollard_rho(n);
	}
	if(is_prime(g)) return g;
	else return pollard_rho(g);
}

int main(){
	unordered_map<ull, ull> cand{};
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n ; i ++){
		unordered_map<ull, bool> check{};
		ull x;
		scanf("%lld", &x);
		while(x > 1){
			ull p = pollard_rho(x);
			if(check[p] == false){
				check[p] = true;
				cand[p]++;
			}
			x /= p;
		}
	}
	ull result = 0;
	for(auto& [_, x]: cand){
		result = std::max(result, x);
	}
	printf("%lld\n", result);

	return 0;
}
