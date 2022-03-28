#include <stdio.h>

int cache[31];

int main(){
	int n;
	scanf("%d", &n);
	
	cache[0] = 1;
	cache[2] = 3;
		
	for(int i = 4; i <= n; i += 2){
		cache[i] = cache[2] * cache[i - 2];
		for(int j = i - 4; j >= 0; j -= 2) cache[i] += (cache[j]) << 1;
	}

	printf("%d\n", cache[n]);

	return 0;
}
