#include <cstdio>

constexpr int N = 200000;
int arr[N] = { 0, };

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	if(n == 2 && k == 1){
		printf("-1\n");
		return 0;
	}

	arr[0] = k;
	int len = 1;
	for(int i = 1; i <= n; i++){
		if(i == k) continue; 
		if(i == k+2) continue;
		arr[len ++] = i;
	}

	if(k + 2 <= n) arr[len++] = k+2;

	for(int i =0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
