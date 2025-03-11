#include <cstdio>
using ll = unsigned long long;

ll pow(ll b, ll e, ll m){
	b %= m;
	ll result = 1;
	while(e){
		if(e&1) result = (b*result) % m;
		b = (b*b)%m;
		e >>= 1;
	}
	return result;
}

bool rabin(ll p, ll x){
	ll d = x-1;
	while(true){
		ll k = pow(p, d, x);
		if(d & 1) return (k == 1 || k == x-1);
		if(k == x-1) return true;
		d >>= 1;
	}
}

bool is_prime(ll x){
	ll p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61};
	for(int i = 0; i < 13; i ++) if(p[i] == x) return true;
	for(int i = 0; i < 13; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}

int main(){
	int n, result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n ; i ++){
		ll x;
		scanf("%lld", &x);
		//2*Area+1 = (2x+1)(2y+1)
		result += is_prime(2*x+1);
	}
	printf("%d\n", result);
	return 0;
}
