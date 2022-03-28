#include <stdio.h>
#include <limits.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int cache[201];
int n, k;

int main(){
	scanf("%d %d", &n, &k);

	scanf("%d", cache+1);
	for(int i = 2; i < n+1; i ++){
		scanf("%d", cache+i);
		cache[i] += cache[i-1];
	}

	int result = INT_MIN;
	for(int i = k; i < n+1; i ++){
		int t = cache[i] - cache[i-k];
		result = MAX(result, t);
	}
	printf("%d\n", result);

	return 0;
}
