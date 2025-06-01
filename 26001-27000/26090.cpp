#include <cstdio>

constexpr int N = 501;
constexpr int P = 600'001;
int arr[N];
bool prime[P];

void build_sieve(){
	for(int i = 0; i < P; i ++) prime[i] = true;
	int idx = 3;
	int k = 3;
	for(int i = 0; idx < P; i ++){
		if(prime[i]){ //2*i+3
			prime[idx] = false;
			for(int j = idx; P - j > k; j += k){
				prime[j+k] = false;
			}
		}
		idx += k;
		k += 2;
		idx += k;
	}
}

bool is_prime(int x){
	if(x == 1) return false;
	if(x == 2) return true;
	if(x % 2 == 0) return false;
	return prime[(x-3)>>1];
}

bool sum_prime(int n, int s, int l){
	if(n < s+l) return false;
	int tmp = 0;
	for(int i = s; i < s+l; i ++)
		tmp += arr[i];
	return is_prime(tmp);
}


int main(){
	build_sieve();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", arr+i);

	int result = 0;
	for(int i = 1; i < n+1 ; i ++){
		if(!is_prime(i)) continue;
		for(int s = 0; s < n; s ++){
			result += sum_prime(n, s, i);
		}
	}
	printf("%d\n", result);
	
	return 0;
}
