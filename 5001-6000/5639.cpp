#include <cstdio>
#include <algorithm>

constexpr int N = 10001;

void print(int* arr, int l, int r){
	printf("print(%d %d)\n", l, r);
	if(l > r) return;
	if(l == r) {
		printf("%d\n", arr[l]);
		return;
	}
	int base = arr[l];
	int m = l+1;
	for(int i = l+1; i <= r; i ++){
		m = i;
		if(base < arr[i]){
			m = i-1;
			break;
		} 
	}
	printf("%d %d, %d %d\n", l+1, m, m+1, r);
	print(arr, l+1, m);
	print(arr, m+1, r);
	printf("%d\n", arr[l]);
}


int main(){
	int arr[N] = { 0, };
	int x, n = 0;

	while(scanf("%d", &x) != EOF)
		arr[n++] = x;
	print(arr, 0, n-1);

	return 0;
}
