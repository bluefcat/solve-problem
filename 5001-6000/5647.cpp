#include <cstdio>

using ll = long long;

int main(){
	ll q = 1;
	while(scanf("%lld", &q) && q != 0){
		ll result = 0, c = (q+1)*q;
		for(ll p = q+1; p < 10e7; p ++){
			ll k = c - (1-p)*p;
			if(k & 1) continue;
			result += (k % (p-q) == 0);
		}
		printf("%lld\n", result);

	}
	return 0;
}
