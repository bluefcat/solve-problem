#include <stdio.h>
#include <stdlib.h>

#define M 500001

int cache_n[M];
int cache_m[M];
int result[M];

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int lower_search(const int* a, const int length, const int target){
	int first = 0, last = length-1, mid = 0;
	
	while(first < last){
		mid = (first + last)/2;
		
		if(a[mid] >= target){
			last = mid;
		}
		else{
			first = mid + 1;
		}	
	}
	return last;
}

int upper_search(const int* a, const int length, const int target){
	int first = 0, last = length-1, mid = 0;
	
	while(first < last){
		mid = (first + last)/2;
		
		if(a[mid] > target){
			last = mid;
		}
		else{
			first = mid + 1;
		}	
	}
	return last;
}



int main(){
	int n, m;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", cache_n + i);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i ++) scanf("%d", cache_m + i);

	//n log n
	qsort(cache_n, n, sizeof(int), compare);
	

	
	for(int i = 0; i < m; i ++){
		int upper = upper_search(cache_n, n, cache_m[i]);
		int lower = lower_search(cache_n, n, cache_m[i]);
		if(upper == n - 1 && cache_n[n-1] == cache_m[i]) upper ++;

		printf("%d ",  upper - lower);
	}
	printf("\n");
	return 0;
}
