#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cross[501][2];
int cache[501];

int compare(const void* x, const void* y){
	return ((int*)x)[0] > ((int*)y)[0];
}

int main(){
	int n, mindex = 0;
	int result = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		int x = 0;
		scanf("%d", &x);
		cross[i][0] = x;
		scanf("%d", cross[i]+1);	

		mindex = MAX(mindex, x);
	}
	qsort(cross, mindex+1, sizeof(int)*2, compare);

	for(int i = 1; i <= mindex; i ++){
		int tmp = 0;
		if(!cross[i][0]) continue;
		for(int j = 1; j < i; j ++){
			if(tmp < cache[j] && cross[j][1] < cross[i][1]) tmp = cache[j];
		}
		cache[i] = tmp+1;
		result = MAX(result, cache[i]);
	}

	printf("%d\n", n-result);

	return 0;
}
