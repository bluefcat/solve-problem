#include <stdio.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int coin[101];
int cache[100001];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i ++) scanf("%d", coin+i);
	qsort(coin, n+1, sizeof(int), compare);
	
	for(int i = 1; i <= k; i ++) cache[i] = 10001;

	for(int i = 1; i <= n; i ++){
		for(int j = coin[i]; j <= k; j ++){
			cache[j] = MIN(cache[j], cache[j-coin[i]]+1);
		}

	}
	


	printf("%d\n", cache[k] != 10001? cache[k]: -1);

	return 0;
}
