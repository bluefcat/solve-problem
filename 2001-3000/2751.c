#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void merge(int* arr, int p, int q, int r){
	int lsize = q-p;
	int rsize = r-q;
	int* larr = (int*)malloc(sizeof(int)*(lsize+1));
	int* rarr = (int*)malloc(sizeof(int)*(rsize+1));

	for(int i = 0; i < lsize; i ++) larr[i] = arr[p+i];
	larr[lsize] = INT_MAX;
	
	for(int i = 0; i < rsize; i ++) rarr[i] = arr[q+i];
	rarr[rsize] = INT_MAX;

	int i = 0, j = 0;

	for(int k = p; k < r; k ++){
		if(larr[i] <= rarr[j]){
			arr[k] = larr[i];
			i ++;
		}
		else{
			arr[k] = rarr[j];
			j ++;
		}
	}


	free(rarr);
	free(larr);
	return ;
}

void merge_sort(int* arr, int p, int r){
	if(p+1 >= r) return;
	int q = (p+r)/2;
	merge_sort(arr, p, q);
	merge_sort(arr, q, r);
	merge(arr, p, q, r);
	return ;
}

int main(){
	int n;
	int* arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);

	merge_sort(arr, 0, n);

	for(int i = 0; i < n; i ++) printf("%d\n", arr[i]);
	
	free(arr);
	return 0;
}
