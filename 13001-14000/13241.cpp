#include <cstdio>
#include <numeric>

using ll = long long;

int main(){
	ll x;
	ll y;
	scanf("%lld %lld", &x, &y);
	printf("%lld\n", x*y/std::gcd(x, y));
	return 0;
}
