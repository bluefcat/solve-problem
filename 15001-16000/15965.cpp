#include <cstdio>
#include <vector>

using lint = long long;
constexpr int P = 7368788;
bool is_prime[P] = { false, };
std::vector<lint> prime;

void build_seive(){
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
	build_seive();
	int n;
	scanf("%d", &n);
	printf("%lld\n", prime[n-1]);

	return 0;
}
