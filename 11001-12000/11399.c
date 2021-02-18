#include <stdio.h>
#include <stdlib.h>

int wait[1001];

int compare(const void* x, const void* y){
	return *(int*)x > *(int*)y;
}

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", wait+i);
	}

	qsort(wait, n, sizeof(int), compare);

	result += wait[0];	
	for(int i = 0; i < n-1; i ++){
		wait[i+1] += wait[i];
		result += wait[i+1];
	}

	printf("%d\n", result);

	return 0;
}
