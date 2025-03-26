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
	if(a == 0 && b == 0 && S == 0){
		printf("YES\n");
		return 0;
	}
	auto [x, y] = eea(a, b);
	lll g = x*(lll)a+y*(lll)b;
	x = x*S/g;
	y = y*S/g;
	if(!(x == 0 && y == 1) && x <= 0){
		lll cnt = (-x)*g/b + 1;
		x += cnt * b/g;
		y -= cnt * a/g;
	}
	if(!(x == 1 && y == 0)&& y <= 0){
		lll cnt = (-y)*g/a + 1;
		x -= cnt * b/g;
		y += cnt * a/g;
	}
	printf("%lld %lld\n", (ll)x, (ll)y);
	if(((x > 0 && y > 0) || (x == 1 && y == 0) || (x == 0 && y == 1)) && (lll)a*x+(lll)b*y == (lll)S){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
