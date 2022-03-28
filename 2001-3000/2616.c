#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cache[50002];
int cache2[50002];
int result[50002];

int main(){
	int n, t;
	scanf("%d", &n);

	for(int i = 1; i <= n; i ++){
		int tmp;
		scanf("%d", &tmp);

		cache[i] = tmp + cache[i-1];
	}

	scanf("%d", &t);

	for(int i = t; i <= n; i ++){
		cache2[i-t] = cache[i] - cache[i-t];
	}


	return 0;
}
