#include <cstdio>
#include <cmath>
#include <vector>

using lint = long long;
constexpr int P = 1'000'001;
bool is_prime[P] = { false, };
std::vector<lint> prime;

void build_sieve(){
	prime.reserve(P);
	for(int i = 2; i < P; i ++) is_prime[i] = true;	
	for(int p = 2; p < P; p ++){
		if(is_prime[p])
			prime.emplace_back(p);
		
		for(auto& q: prime){
			if(p*q >= P) break;
			is_prime[p*q] = false;
			if(p%q == 0) break;
		}
	}
}


int main(){
	build_sieve();
	int n = 0;
	while(scanf("%d", &n) && n != 0){
		int x, y;
		for(auto& p: prime){
			x = p;
			if(is_prime[n-x]){
				y = n-x;
				break;
			}
		}
		printf("%d = %d + %d\n", n, std::min(x, y), std::max(x, y));
	}
	return 0;
}
