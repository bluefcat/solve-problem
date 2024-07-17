#include <cstdio>
#include <vector>
#define N 4000001

void make_prime(std::vector<int>& prime){
	bool prime_table[N] = { false, };
	for(int i = 0; i < N; i ++) 
		prime_table[i] = true;
	prime_table[0] = false;
	prime_table[1] = false;
	
	for(int idx = 0; idx < N; idx ++){
		if(!prime_table[idx]) continue;
		prime.push_back(idx);
		for(int cur = 2*idx; cur < N; cur += idx)
			prime_table[cur] = false;
	}
	return;
}

int main(){
	std::vector<int> prime{}; 
	make_prime(prime);
	int n, result = 0;	
	int l = 0, r = 0, sum = prime[0];
	
	scanf("%d", &n);

	while(l <= r && (l < N && r < N)){
		if(sum == n){
			result ++;
			sum -= prime[l];
			l ++;
		}
		else if(sum < n){
			r ++;
			sum += prime[r];
		}
		else{
			sum -= prime[l];
			l ++;
		}
	}

	printf("%d\n", result);

	return 0;
}
