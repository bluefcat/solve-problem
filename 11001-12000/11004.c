#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	int n, k;
	int arr[5000001] = { 0, };
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);

	qsort(arr, n, sizeof(int), compare);

	printf("%d\n", arr[k-1]);

	return 0;
}
