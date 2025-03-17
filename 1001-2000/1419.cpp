#include <cstdio>
#include <algorithm>

using lint = long long;

int main(){
	lint l, r, k;
	scanf("%lld %lld %lld", &l, &r, &k);
	
	lint d = ((k-1) * k) >> 1;
	printf("%lld\n", std::max((r-d)/k, (r-k)/d));	
	return 0;
}
