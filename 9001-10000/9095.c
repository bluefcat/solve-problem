#include <stdio.h>

int cache[12];

int main(){
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;

	int t, n;
	scanf("%d", &t);

	for(int i = 0; i < t; i ++){
		scanf("%d", &n);
		
		if(cache[n] != 0){
			goto PRINT;
		}

		for(int x = 4; x <= n; x ++){
			cache[x] = cache[x-1] + cache[x-2] + cache[x-3];
		}
PRINT:
		printf("%d\n", cache[n]);
	}
}
