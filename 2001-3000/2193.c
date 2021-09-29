#include <stdio.h>

long long cache_z[91];
long long cache_o[91];

int main(){
	cache_z[0] = 0;
	cache_z[1] = 0;
	cache_z[2] = 1;

	cache_o[0] = 0;
	cache_o[1] = 1;
	cache_o[2] = 0;
	
	int n = 0;
	scanf("%d", &n);

	for(int i = 3; i <= n; i ++){
		cache_z[i] = cache_z[i-1] + cache_o[i-1];
		cache_o[i] = cache_z[i-1];
	}

	printf("%lld\n", cache_z[n] + cache_o[n]);

	return 0;
}
