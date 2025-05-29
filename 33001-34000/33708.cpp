#include <cstdio>

constexpr int N = 200'001;
constexpr int P = 500'000;

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
				prime[j] = false;
			}
		}
		idx += k;
		k += 2;
		idx += k;
	}
}

int main(){
	build_sieve();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	
	bool flag = true;
	int one = 0, comp = 0;
	for(int i = 0; i < n-1; i ++){
		flag &= (arr[i] <= arr[i+1]);

		one += arr[i] == 1;
		if(arr[i] > 2 && arr[i] % 2 == 0)
			comp += 1;
		else if(arr[i] > 2){
			comp += !prime[(arr[i]-3)/2];
		}
	}

	if(flag){
		printf("YES\n");
		return 0;
	}	

	if(one == 0 || one <= comp){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");

	return 0;
}
