#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int* arr, int l, int r){
	int pidx = r-1;
	int pivot = arr[r-1];
	int c = l;

	for(int i = l; i < pidx; i ++){
		if(arr[i] < pivot){
			swap(arr+i, arr+c);
			c ++;
		}
	}

	swap(arr+c, arr+pidx);
	return c;
}

void quicksort(int* arr, int l, int r){
	if(l >= r) return;
	
	int pidx = partition(arr, l, r);
	quicksort(arr, l, pidx);
	quicksort(arr, pidx+1, r);
}

int main(){
	
	int n, result = 0;
	int cache[100001] = { 0, };

	scanf("%d", &n);

	for(int i = 0; i < n; i ++)	scanf("%d", cache+i);
	quicksort(cache, 0, n);

	for(int i = 0; i < n; i ++){
		result = MAX(result, (n-i)*cache[i]);
	}
	
	printf("%d\n", result);

	return 0;
}	
