#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int coin[101];
int cache[2][10001];

void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(int* arr, int l, int r){
	int pidx = r-1;
	int pivot = arr[pidx];

	int c = l;
	for(int i = l; i < pidx; i ++){
		if(arr[i] < pivot){
			swap(arr+i, arr+c);
			c ++;
		}
	}

	swap(arr+pidx, arr+c);
	return c;
}

void quicksort(int* arr, int l, int r){
	if(l+1 >= r) return;

	int pidx = partition(arr, l, r);
	
	quicksort(arr, l, pidx);
	quicksort(arr, pidx+1, r);
	return;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i ++) scanf("%d", coin+i);
	quicksort(coin, 0, n+1);
	
	//init
	for(int i = 0; i < 2; i ++) cache[i][0] = 1;

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			cache[i%2][j] = cache[(i-1)%2][j];
			if(j >= coin[i]){
				cache[i%2][j] += cache[i%2][j-coin[i]];
			}
		}
	}
	
	printf("%d\n", cache[n%2][k]);

	return 0;
}
