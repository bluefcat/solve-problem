#include <cstdio>
#include <algorithm>

int arr[100001];

int search(const int n, int r){
	int start = 0;
	int end = r - 1;
	while(end - start >= 0){
		int mid = (start + end)/2;

		if(arr[mid] == n){
			return 1;
		}
		else if(arr[mid] > n){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return 0;
}

int main(){
	int N = 0, M = 0;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i ++){
		scanf("%d", arr+i);
	}
	
	std::sort(arr, arr+N);

	scanf("%d", &M);
	for(int i = 0; i < M; i ++){
		int k = 0;
		scanf("%d", &k);
		printf("%d\n", search(k, N));
	}

	return 0;
}