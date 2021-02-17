#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int arr[1001];
int cache_lis[1001];
int cache_lds[1001];

int main(){
	int n, result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", arr+i);
		cache_lis[i] = 1;
		cache_lds[i] = 1;
	}

	//find the LIS
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < i; j ++){
			if(arr[j] < arr[i]) cache_lis[i] = MAX(cache_lis[i], cache_lis[j]+1);
		}	
	}

	//find the LDS
	for(int i = n-1; i >= 0; i --){
		for(int j = n-1; j >= i; j --){
			if(arr[j] < arr[i]) cache_lds[i] = MAX(cache_lds[i], cache_lds[j]+1);
		}	
	}

	//find the answer
	for(int i = 0; i < n; i ++){
		result = MAX(result, cache_lis[i]+cache_lds[i]-1);
	}
	printf("%d\n", result);

	return 0;
}
