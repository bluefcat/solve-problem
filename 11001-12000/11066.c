#include <stdio.h>
#include <stdlib.h>

int novel[501];

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int T = 0;

	scanf("%d", &T);
	
	for(int t = 0; t < T; t ++){
		int K = 0;
		scanf("%d", &K);
		
		for(int i = 0; i < K; i ++) scanf("%d", novel + i);
		
		qsort(novel, sizeof(int), K, compare);

		for(int i = 0; i < K; i ++) printf("%d ", novel[i]);
		printf("\n");
		
	}
	return 0;
}
