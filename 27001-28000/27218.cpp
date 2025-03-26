#include <cstdio>
#include <unordered_map>

constexpr int N = 200001;
bool prime[N] = { false };

int main(){
	prime[2] = true;
	for(int i = 3; i < N; i += 2) prime[i] = true;

	for(int i = 3; i < N; i += 2)
		for(int j = 2; i * j < N; j ++)
			prime[i*j] = false;

	int n;
	std::unordered_map<int, int> factors{};
	scanf("%d", &n);
	
	int m = n;
	int p = 2;
	while(m != 0){
		while(m % p == 0){
			factors[p] ++;
			m /= p;
		}

		p ++;
		if(m < p) break;
		for(;!prime[p]; p ++);
	}


	for(auto& [f, c]: factors){
		printf("%d^%d+", f, c);
	}
	printf("\n");


	return 0;
}
