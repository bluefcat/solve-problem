#include <cstdio>

using i128 = __int128; //unsigned long long; //std::uint64_t;
using lint = long long;

constexpr i128 mod = 1'000'000'007;

i128 bmod(i128 x, i128 m){
	return x-(x/m)*m;
}

i128 fact(i128 n, i128 m){
	i128 result = 1;
	for(i128 i = 0; i < n; i ++)
		result = bmod(result*(i+1), m);
	
	return result;
}

i128 mpow(i128 x, i128 e, i128 m){
	i128 result = 1;
	while(e){
		if(e & 1) result = bmod(result*x, m);
		x = bmod(x*x, m);
		e >>= 1;
	}
	return bmod(result, m);
}

int main(){
	lint n, k;
	scanf("%lld %lld", &n, &k);
	lint a = fact(n, mod);
	lint b = fact(k, mod) * fact(n-k, mod);
	lint c = mpow(b, mod-2, mod);
	printf("%llu\n", (lint)bmod(a*c, mod));
	return 0;
}
