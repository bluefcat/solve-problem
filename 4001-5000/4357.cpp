#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using lint = long long;
using unordered_map = std::unordered_map<lint, lint>;
using std::min;

lint mpow(lint x, lint e, lint m){
	lint result = 1;
	while(e){
		if(e&1) result = (result * x) % m;
		x = (x * x) % m;
		e >>= 1;
	}
	return result;
}

unordered_map cache{};

int main(){
	lint p, b, n; 
	while(scanf("%lld %lld %lld", &p, &b, &n) != EOF){
		cache.clear();
		lint sn = std::sqrt(n)*5;
			
		lint invb = mpow(b, p-2, p);
		lint x = n;
		for(lint i = 0; i < sn; i ++){
			if(cache[x] != 0) cache[x] = min(cache[x], i);
			else cache[x] = i;
			x = (x * invb) % p;
		}
		
		lint base = mpow(b, sn, p);
		x = 1;
		for(lint i = 0; i <= sn; i ++){
			if(cache.find(x) != cache.end()){
				printf("%lld\n", i * sn + cache[x]);
				goto END;
			}	
			x = (x * base) % p;
		}
		printf("no solution\n");
END:
		continue;
	}

	return 0;
}
