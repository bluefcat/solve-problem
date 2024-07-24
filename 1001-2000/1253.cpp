#include <cstdio>
#define N 2001

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort(int* arr, int sidx, int eidx){
	if(sidx+1 >= eidx) return;
	int pidx = sidx;
	int pivot = arr[pidx];

	int i = sidx+1;
	int j = eidx-1;

	do{
		while(i < eidx && arr[i] < pivot) i ++;
		while(j > sidx && arr[j] > pivot) j --;
		if(i < j) swap(arr+i, arr+j);
	}while(i < j);
	
	swap(arr+j, arr+pidx);
	pidx = j;
	sort(arr, sidx, pidx);
	sort(arr, pidx+1, eidx);
}

int search(int* arr, int sidx, int eidx, int n){
	int result = -1;	
	while(sidx < eidx){
		int midx = (sidx + eidx) >> 1;
		if(arr[midx] == n) return midx;
		if(arr[midx] > n){
			eidx = midx;
		}
		else{
			sidx = midx + 1;
		}

	}
	return result;
}

int main(){
	int n, result = 0;
	int arr[N] = { 0, };
	int check[N] = { 0, };
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	sort(arr, 0, n);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j) continue;
			int k = arr[i] + arr[j];
			
			int r = search(arr, 0, n, k);
			if((r != -1 && r != i && r != j) && check[k] == 0){
				check[k] = 1;
				result ++;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
