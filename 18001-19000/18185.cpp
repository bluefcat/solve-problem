#include <cstdio>
#include <algorithm>

constexpr int N = 10000;
int arr[N] = { 0, };

int main(){
	int n, result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);

	for(int i = 0; i < n; i ++){
		while(arr[i] != 0){
			if(i < n-2 && arr[i+1] >= arr[i] && arr[i+2] >= arr[i+1]){
				int cnt = std::min(
					{arr[i], arr[i+1], arr[i+2]}
				);
				result += 7*cnt;
				arr[i] -= cnt; arr[i+1] -= cnt; arr[i+2] -= cnt;
			}
			else if(i < n-1 && arr[i+1] >= arr[i]){
				int cnt = std::min(
					{arr[i], arr[i+1]}
				);
				if(i < n-2 && arr[i+2] < arr[i+1]){
					cnt = std::min(cnt, arr[i+2]);
				}
				result += 5*cnt;
				arr[i] -= cnt; arr[i+1] -= cnt;
			}
			else{
				result += 3*arr[i];
				arr[i] = 0;
			}
		}
		for(int j = 0; j < n; j ++) printf("%d ", arr[j]); printf("[%d]\n", result);
	}
	
	printf("%d\n", result);	
	


	return 0;
}
