#include <cstdio>

constexpr int N = 1001;

int main(){
	int arr[N] = { 0, };
	int n, result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n ; i ++)
		scanf("%d", arr+i);

	for(int p = 0; p < n; p ++){
		int tmp = 0;
		for(int i = 0; i < n; i ++){
			if(i == p) continue;
			tmp ^= arr[i];
		}
		if(tmp < arr[p]) result ++;
	}
	printf("%d\n", result);
	return 0;
}
