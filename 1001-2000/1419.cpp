#include <cstdio>
#include <algorithm>
#include <numeric>
#include <utility>

using lint = long long;

int main(){
	lint l, r, k;
	scanf("%lld %lld %lld", &l, &r, &k);
	
	lint d = ((k-1) * k) >> 1;
	if(k <= 3){
		std::swap(d, k);
	}
	lint result = 0;

	for(lint y = 1; y <= std::gcd(k, d); y ++){
		lint rx = (r - d*y)/k;
		lint lx = std::max((l - d*y)/k + ((l - d*y) % k != 0), (lint)1);

		result += (rx - lx) + 1;
	}
	if(k == 3) result >>= 1;
	printf("%lld\n", result);


	return 0;
}
