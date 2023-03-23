#include <stdio.h>
#include <stdlib.h>
#define MAXN 1001

int weights[MAXN];
int compare(const void* x, const void* y){
	return *(int*)x > *(int*)y;
}


int main(){
	int result = 1;
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++) scanf("%d", weights+i);
	
	qsort(weights, n, sizeof(int), compare);

	for(int i = 0; i < n; i ++){
		if(result < weights[i]) break;
		result += weights[i];
	}

	printf("%d\n", result);

	return 0;
}
