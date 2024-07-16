#include <cstdio>
constexpr int N = 7;

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void copy(int arr[][N], int result[][N], int n){
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			result[i][j] = arr[i][j];
}

void minor(int arr[][N], int result[][N], int n, int i, int j){
	int r = 0;
	for(int p = 0; p < n; p ++){
		if(p == i) continue;
		int c = 0;
		for(int q = 0; q < n; q ++){
			if(q == j) continue;
			result[r][c] = arr[p][q];
			c ++;
		}
		r ++;
	}
}

void transpose(int arr[][N], int result[][N], int n){
	copy(arr, result, n);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < i; j ++)
			swap(result[i]+j, result[j]+i);		
}

int det(int arr[][N], int n){
	if(n == 1) return arr[0][0];

	int result = 0;
	for(int i = 0; i < n; i ++){
		int tmp[N][N] = { 0, };
		minor(arr, tmp, n, i, 0);
		result += ((i&1)?-1:1) * arr[i][0] * det(tmp, n-1);
	}
	return result;
}


void inv(int arr[][N], int result[][N], int n){
	if(n == 1){
		result[0][0] = 1;
		return;
	}
	int trans[N][N] = { 0, };
	copy(arr, trans, n);
	transpose(arr, trans, n);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			int tmp[N][N] = { 0, };
			minor(trans, tmp, n, i, j);
			int d = det(tmp, n-1);
			result[i][j] = (((i+j)&1)?-1:1) * d;
		}
	}
}

void mul(int d, int arr[][N], int ans[N], int result[N], int n){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			result[i] += arr[i][j] * ans[j];
		}
		result[i] /= d;
	}
}

int main(){
	int n;
	int arr[N][N] = { 0, };
	int invm[N][N] = { 0, };
	int ans[N] = { 0, };
	int result[N] = { 0, };
	
	scanf("%d", &n);
	for(int i = 0 ; i < n; i ++){
		for(int j = 0; j < n; j ++) scanf("%d", arr[i]+j);
		scanf("%d", ans+i);
	}

	int d = det(arr, n);
	inv(arr, invm, n);
	mul(d, invm, ans, result, n);
	
	for(int i = 0; i < n; i ++) printf("%d ", result[i]);
	printf("\n");

	return 0;
}
