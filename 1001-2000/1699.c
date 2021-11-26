#include <stdio.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int cache[100001];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i <= n; i ++) cache[i] = i;

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j*j <= i; j ++){
			cache[i] = MIN(cache[i], cache[i-j*j] + 1);
		}
	}

	printf("%d\n", cache[n]);


	return 0;
}
