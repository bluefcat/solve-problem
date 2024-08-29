#include <cstdio>
#include <utility>

using ll = long long;
using pair = std::pair<ll, ll>;
constexpr int N = 100001;
bool prime[N] = { 0, };

pair gcd(ll u, ll v){
	ll s[2] = { 1, 0 };
	ll t[2] = { 0, 1 };

	while(v > 0){
		ll q = u/v;
		ll r = u%r;
		ll ns = s[0] - q*s[1];
		ll nt = t[0] - q*t[1];
		u = v, v = r;
		s[0] = s[1], s[1] = ns;
		t[0] = t[1], t[1] = nt;
	}
	

	return {s[0], t[0]};
}

ll mpow(ll x, ll d, ll m){
	ll result = 1;
	while(d){
		if(d & 1){
			result = (result*x)%m;
		}
		x = (x*x)%m;
		d >>= 1;
	}
	return result%m;
}

void get_prime(){
	prime[2] = true;
	for(int i = 3; i < N; i += 2)
		prime[i] = true;
	
	for(int i = 3; i < N; i += 2){
		if(prime[i] == false) continue;
		for(int j = 2; i*j < N; j ++) prime[i*j] = false;
	}
	return ;
}

int main(){
	get_prime();
	ll phi, n, e, c;
	scanf("%lld %lld %lld", &n, &e, &c);

	//get private key
	for(ll i = 3; i < N; i ++){
		if(prime[i] && (n % i == 0)){
			phi = (i-1)*((n/i)-1);
			break;
		}
	}

	auto [d, _] = gcd(e, phi);
	if(d <= 0) d += ((-d)/phi+1)*phi;
	printf("%lld\n", mpow(c, d, n));
	return 0;
}
