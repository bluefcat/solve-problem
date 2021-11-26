#include <stdio.h>
#include <stdlib.h>

int cache[100001];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", cache + i);
	}
	
	qsort(cache, n, sizeof(int), compare);

	int x;
	scanf("%d", &x);
	
	int l = 0, r = n-1;
	
	while(l < r){
		int sum = cache[l] + cache[r];

		if(sum > x){
			r --;
		}
		else if(sum < x){
			l ++;
		}
		else{
			result ++;
			l ++; r --;
		}
	}
	
	printf("%d\n", result);

	return 0;
}
