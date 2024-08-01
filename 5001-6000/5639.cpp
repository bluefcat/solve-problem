#include <cstdio>

constexpr int N = 10001;

void print(int* arr, int l, int r){
	if(l > r) return;
	if(l == r) {
		printf("%d\n", arr[l]);
		return;
	}
	int base = arr[l];
	int m = l+1;
	for(int i = l+1; i <= r; i ++){
		if(base < arr[i]){
			m = i-1;
			break;
		}
	}

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
