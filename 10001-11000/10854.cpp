#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include <cmath>

using ll = __int128;
using ull = unsigned long long;
using std::vector;

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
		2, 3, 5, 7, 11, 13, 17, 19 ,23, 29, 31, 37
	};
	for(int i = 0; i < 12; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 12; i ++){
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
	ull n;
	ull result = 1;
	scanf("%llu", &n);
	vector<ull> v{};
	
	while(n > 1){
		ull p = pollard_rho(n);
		v.push_back(p);
		n /= p;
	}
	std::sort(v.begin(), v.end());
	ull p = v[0], cnt = 1;
	for(int i = 1; i < v.size(); i ++){
		if(p != v[i]){
			result *= (cnt+1);
			p = v[i];
			cnt = 1;
			continue;
		}	
		cnt ++;
	}
	result *= (cnt+1);
	printf("%llu\n", result);
	return 0;
}
