#include <cstdio>

constexpr int N = 100000+1;
int arr[N] = { 0, };

int main(){
	int n, k;
	long long result = 0;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	
	int m = arr[0]; 
	int idx = 0;
	int M = arr[0];
	for(int i = 1; i < n; i ++){
		if(m > arr[i]){
			m = arr[i];
			idx = i;
		}
		if(M < arr[i]) M = arr[i];
	}

	if(m <= 0){
		printf("-1\n");
		return 0;
	}
	if(M > k){
		printf("0\n");
		return 0;
	}
	
	for(int i = 0; i < n; i ++){
		if(i == idx) continue;
		result += (k-arr[i])/m;
	}

	printf("%lld\n", result +1);
	


	return 0;
}
