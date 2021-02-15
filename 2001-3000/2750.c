#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
	return;
}

void bubble_sort(int* arr, int s, int f){
	for(int i = f-1; i >= 0; i --){
		for(int j = s; j < i; j ++){
			if(arr[j] > arr[j+1]) swap(arr+j, arr+j+1);
		}
	}
	return;
}

int main(){
	int n;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);

	bubble_sort(arr, 0, n);

	for(int i = 0; i < n; i ++) printf("%d\n", arr[i]);

	free(arr);
	return 0;
}
