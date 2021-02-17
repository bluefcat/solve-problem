#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cache[10003];
int wine[10003];

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 3; i < n+3; i ++){
		scanf("%d", wine+i);
	}
	
	for(int i = 3; i < n+3; i ++){
		cache[i] = MAX(wine[i]+wine[i-1]+cache[i-3], wine[i]+cache[i-2]);
		cache[i] = MAX(cache[i], cache[i-1]);
		result = MAX(result, cache[i]);
	}
	
	printf("%d\n", result);

	return 0;
}
