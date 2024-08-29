#include <cstdio>
#include <utility>

using ll = long long;
using lll = __int128;

std::pair<lll, lll> eea(ll u, ll v){
	ll s[2] = { 1, 0 };
	ll t[2] = { 0, 1 };
	while(v > 0){
		ll q = u / v;
		ll r = u % v;
		ll ns = s[0] - q*s[1];
		ll nt = t[0] - q*t[1];

		u = v, v = r;
		s[0] = s[1], s[1] = ns;
		t[0] = t[1], t[1] = nt;
	}

	return {s[0], t[0]};
}

int main(){
	ll a, b, S;
	scanf("%lld %lld %lld", &a, &b, &S);
	auto [x, y] = eea(a, b);
	ll g = x*a+y*b;
	x = x*S/g;
	y = y*S/g;
	if(x <= 0){
		lll cnt = (-x)*g/b + 1;
		x += cnt * b/g;
		y -= cnt * a/g;
	}
	if(y <= 0){
		lll cnt = (-y)*g/a + 1;
		x -= cnt * b/g;
		y += cnt * a/g;
	}
	if(x > 0 && y > 0 && a*x+b*y == (lll)S){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
