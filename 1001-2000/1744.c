#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)y - *(int*)x;
}

int main(){
	int n, result = 0;
	int cache[51] = { 0, };

	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", cache+i);

	qsort(cache, n, sizeof(int), compare);
	
	int c = cache[0];
	int f = 1;
	for(int i = 1; i < n; i ++){

		if(c * cache[i] > 1){
			result += c * cache[i];
			c = cache[++i];
			f = 0;
		}
		else if(cache[i] < 0 && (c * cache[i] == 0 || c * cache[i] == 1)){
			result += c * cache[i];
			c = cache[++i];
			f = 0;
		}
		else{
			result += c;
			c = cache[i];
			f = 1;
		}

	}

	if(f) result += c;

	printf("%d\n", result);

	return 0;
}
