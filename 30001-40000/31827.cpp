#include <cstdio>
#include <vector>

using std::vector;

constexpr int N = 1000001;

bool is_prime[N] = { false };
vector<int> primes[10];

constexpr int get_idx(int p){
	return (p-1) >> 1;
}

void init(){
	is_prime[2] = true;
	for(int i = 3; i < N; i += 2)
		is_prime[i] = true;
	
	for(int i = 3; i < N; i += 2){
		if(!is_prime[i]) continue;
		for(int j = 2; i * j < N; j ++)
			is_prime[i*j] = false;
	}

}


int main(){
	init();

	for(int i = 3; i < N; i ++){
		for(int n = 3; n < 10; n ++){
			if(!is_prime[i] || get_idx(i) % n != 0) 
				continue;
			primes[n].push_back(i);
		
		}
	}
	
	int n, k;
	scanf("%d %d", &n, &k);
	int mk = k;
	if(k == 2) k = 3;
	if(k == 8) k = 4;

	for(int i = 0; i < n; i ++){
		printf("%d ", primes[k][i]);	
	}	
	printf("\n");


	return 0;
}
