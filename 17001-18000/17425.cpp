#include <cstdio>
#include <vector>


using lint = long long;
constexpr lint P = 1'000'001;
lint lpf[P] = { 0, };
lint f[P] = { 0, };
bool c[P] = { false, };
std::vector<lint> prime;

void build_sieve(){
	for(int p = 2; p < P; p ++){
		if(lpf[p] == 0)
			prime.emplace_back(p);
		
		for(auto& q: prime){
			if(p*q >= P) break;
			lpf[p*q] = q;
			if(p%q == 0) break;
		}
	}
}

void build_f(){
	f[1] = 1;
	for(lint p = 2; p < P; p ++){
		if(f[p] != 0) continue;
		if(lpf[p] != 0) continue;

		lint q = p; f[p] = 1;
		while(q < P){
			c[q] = true;
			f[q] = f[q/p] + q;	

			for(int k = 1; k < P; k ++){
				if(k*q >= P) break;
				if(!c[k]) continue;
				c[k*q] = true;
				f[k*q] = f[k]*f[q];
			}
			q *= p;
		}
	}
}

int main(){
	build_sieve();
	build_f();
	for(int i = 1; i < P-1; i ++) f[i+1] += f[i];
	
	int t;
	scanf("%d\n", &t);
	while(t--){
		int i;
		scanf("%d", &i);
		printf("%lld\n", f[i]);

	}


	return 0;
}
