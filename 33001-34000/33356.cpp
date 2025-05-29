#include <cstdio>

constexpr int N = 2*10'000;

int get_cycle(int* arr){
	int idx = 0;
	int cnt = 0;
	do{
		idx = arr[idx] - 1;
		cnt ++;
		printf("%d\n", idx);
	}while(idx != 0);
	return cnt;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		int arr[N] = { 0, };
		if(n & 1){
			printf("%d\n", n);
			for(int i = 0; i < n >> 1; i ++){
				printf("%d %d ", n-i, i+1);
				arr[2*i] = n-i, arr[2*i+1] = i+1;
			}
			arr[n-1] = n-(n>>1);
			printf("%d ", n-(n>>1));
			for(int i = 0; i < n; i ++) printf("%d", arr[i]);
			//printf("[%d]", get_cycle(arr));
			printf("\n");
		} else {
			printf("%d\n", n);
			for(int i = (n >> 1)-1; i >= 0; i --){
				printf("%d %d ", i+1, n-i);
			}
			printf("\n");
		}
	}

	return 0;
}
