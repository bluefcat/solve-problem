#include <cstdio>
#include <utility>

using ll = long long;

std::pair<ll, ll> eea(ll u, ll v){
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
	int t;
	scanf("%d", &t);
	while(t--){
		ll k, c;
		bool flag = false;
		scanf("%lld %lld", &k, &c);
		auto [x, y] = eea(k, c);
		if(x*k+y*c != 1){
			printf("IMPOSSIBLE\n");
		}
		else{
			
			if(x < 0 && y > 0){
			}
			else if(x >= 0){
				while(x >= 0 || y <= 0){
					x -= c;
					y += k;
				}
			}
			else if(x < 0){
				while(x >= 0 || y <= 0){
					x += c;
					y -= k;
				}
			}

			if(y > 1000000000){
				printf("IMPOSSIBLE\n");
			}
			else{
				printf("%lld\n", y);
			}
		}
	}
}
