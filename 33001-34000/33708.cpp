#include <cstdio>

constexpr int N = 200'001;
constexpr int P = 500'000;

int arr[N];
int prime[P];

void build_sieve(){
	for(int i = 0; i < P; i ++) prime[i] = true;
	int idx = 3;
	int k = 3;
	for(int i = 0; idx < P; i ++){
		if(prime[i]){ //2*i+3
			prime[idx] = false;
			for(int j = idx; P - j > k; j += k){
				prime[j] = false;
			}
		}
		idx += k;
		k += 2;
		idx += k;
	}
}

bool is_prime(int i){
	if(i == 1) return false;
	if(i == 2) return true;
	if(i % 2 == 0) return false;
	return prime[(i-3) >> 1];
}

int main(){
	build_sieve();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	
	bool flag = true;
	for(int i = 0; i < n; i ++){
		if(i < n-1){
			flag &= (arr[i] <= arr[i+1]);
			if(is_prime(arr[i]) && is_prime(arr[i+1])){
				flag = true;
				break;
			}
		}

		if(arr[i] != 1 && !is_prime(arr[i])){
			flag = true;
			break;
		}
	}

	if(flag){
		printf("YES\n");
		return 0;
	}	

	printf("NO\n");
	return 0;
}
