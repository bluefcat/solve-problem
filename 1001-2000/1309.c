#include <stdio.h>

int cache[100001];

int main(){
	cache[0] = 1;
	cache[1] = 3;

	int n;
	scanf("%d", &n);

	for(int i = 2; i <= n; i ++){
		cache[i] = (2 * cache[i-1] + cache[i-2]) % 9901;
	}

	printf("%d\n", cache[n]);
	return 0;
}
