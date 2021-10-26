#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int rmax(int* base, int* check, int size){
	int idx = -1, result = 0;
	for(int i = 0; i < size; i ++){
		if(check[i]) continue;

		if(result < base[i]){
			result = base[i];
			idx = i;
		}

	}
	check[idx] = 1;
	return result;
}

int main(){
	int A[51] = { 0, };
	int B[51] = { 0, };
	int C[51] = { 0, };

	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0; i < 2; i ++){
		int *p = (i == 0)? A: B;
		for(int j = 0; j < n; j ++){
			scanf("%d", p+j);
		}
	}
	qsort(A, n, sizeof(int), compare);

	for(int i = 0; i < n; i ++){
		int t = rmax(B, C, n);	
		result += t * A[i];
	}

	printf("%d\n", result);

	return 0;
}
