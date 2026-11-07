#include <stdio.h>
#define N 1000000

int search(int* arr, int length, int target){
	//get index
	int low = 0;
	int high = length-1;
	int mid = 0;

	while(low < high){
		mid = (low + high) >> 1;

		if(arr[mid] >= target) high = mid;
		else low = mid + 1;
	}

	return high;
}

int main(){
	int length = 0;
	int n;
	int arr[N] = { 0, };
	int target[N] = { 0, };

	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	
	//init
	target[length++] = arr[0];

	for(int i = 1; i < n; i ++){
		if(target[length-1] >= arr[i]){
			int index = search(target, length, arr[i]);
			target[index] = arr[i];
		}
		else{
			target[length++] = arr[i];
		}
	}

	printf("%d\n", length);

	return 0;
}
