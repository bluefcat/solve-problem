#include <stdio.h>


int cache[1001];

int main(){

	cache[0] = 1;
	cache[1] = 1;

	int n = 0;
	scanf("%d", &n);

	for(int i = 2; i <= n; i ++){
		cache[i] += cache[i-1] % 10007;
		cache[i] += (cache[i-2]) * 2 % 10007;
		cache[i] %= 10007;
	}

	printf("%d\n", cache[n]);

	return 0;
}

