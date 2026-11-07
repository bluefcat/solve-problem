#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)x > *(int*)y;
}

int main(){
	int arr[5]; 
	int avg = 0;
	for(int i = 0; i < 5; i ++){
		scanf("%d", arr+i);
		avg += arr[i];
	}
	
	qsort(arr, 5, sizeof(int), compare);

	printf("%d\n%d\n", avg/5, arr[2]);

	return 0;
}
