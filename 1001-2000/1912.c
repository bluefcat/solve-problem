#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cache[100001];

int main(){
	int result;
	int n, arr[100001];

	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", arr+i);
	}
	
	cache[0] = arr[0];
	result = arr[0];

	for(int i = 1; i < n; i ++){
		cache[i] = MAX(cache[i-1]+arr[i], arr[i]); 
		result = MAX(result, cache[i]);
	}

	printf("%d\n", result);
	return 0;
}
