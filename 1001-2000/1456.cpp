#include <cstdio>
#include <cmath>
#include <vector>

using lint = long long;
constexpr int P = 10'000'000;
bool is_prime[P] = { false, };
std::vector<lint> prime;

void build_sieve(){
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
	lint a, b;
	scanf("%lld %lld", &a, &b);
	lint result = 0;
	for(lint p = 2; p < P; p ++){
		if(!is_prime[p]) continue;
		for(lint q = p*p; q < b; q *= p){
			result += (a <= q && q <= b);
		}
	}

	printf("%lld\n", result);

	return 0;
}
