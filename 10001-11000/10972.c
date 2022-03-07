#include <stdio.h>
#include <stdlib.h>

int n;
int cache[10001];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", cache+i);
	
	int idx = 0;
	
	for(idx = n-1; idx > 1; idx --){
		if(cache[idx-1] < cache[idx]) break;
	}

	if(n == 1 || (idx == 1 && cache[0] >= cache[1])){
		printf("%d\n", -1);
		return 0;
	}
	for(int i = n-1; i >= idx; i --){
		if(cache[idx-1] < cache[i]){
			int tmp = cache[idx-1];
			cache[idx-1] = cache[i];
			cache[i] = tmp;
			break;
		}
	}
	
	qsort(cache+idx, n-idx, sizeof(int), compare);
	
	for(int i = 0; i < n; i ++){
		printf("%d ", cache[i]);
	}
	printf("\n");


	return 0;
}
