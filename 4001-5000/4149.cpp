#include <iostream>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

using ll = __int128;
using ull = unsigned long long;
using std::gcd;
using std::queue;
using std::vector;

ull pow(ull base, ull exp, ull mod){
	ll result = 1;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return (ull)result;
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
		2, 3, 5, 7, 11, 13, 17, 19 ,23, 29, 31, 37, 61
	};
	for(int i = 0; i < 13; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 13; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}

ll f(ll x, ll n){
	return (((x*x)%n)+1)%n;
}

ull pollard_rho(ll n){
	ll x = rand()%(n-2)+2;
	ll y = x;
	ll g = 1;
	while(g == 1){
		x = f(x, n);
		y = f(f(y, n), n);

		g = gcd(std::abs(x-y), n);
		if(g == n) return pollard_rho(n);
	}
	return g;
}

int main(){
	std::cin.tie(NULL)->sync_with_stdio(false);
	std::cout.tie(NULL)->sync_with_stdio(false);
	
	ull n;
	std::cin >> n;
	queue<ull> q{};
	vector<ull> v{};

	q.push(n);
	while(!q.empty()){
		ll x = q.front(); q.pop();
		while((x&1) == 0){
			v.push_back(2);
			x >>= 1;
		}
		if(x == 1) break;
		if(is_prime(x)){
			v.push_back(x);
			continue;
		}
		ll r = pollard_rho(x);
		q.push(r);
		q.push(x/r);
	}
	
	std::sort(v.begin(), v.end());
	for(auto& x: v){
		std::cout << x << std::endl;
	}

	return 0;
}
