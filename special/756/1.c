#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) < (Y))? (X): (Y))

long tower[1000001];
long cache[1000001];

int main(){
	int n; long result = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%ld", tower + i);
	
	for(int i = 0; i < n; i ++){
		result = MAX(result, tower[i]);
	}

	for(int i = 1; i < n-1; i ++){
		long tmp = MIN(tower[i-1], tower[i+1]);
		result = MAX(result, tmp + tower[i]);
		cache[i] = tower[i] + tmp;
	}

	for(int i = 0; i < n; i ++) printf("%ld\t", cache[i]);
	printf("\n");
	printf("%ld\n", result);

	return 0;
}
