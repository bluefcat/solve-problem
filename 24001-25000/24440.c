#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 1000001
#define INTMAX 2000000

int cache[NMAX], pcache[NMAX][2];
int cache2[NMAX], pcache2[NMAX][2];

int main(){
	for(int i = 0; i < NMAX; i ++) cache[i] = INTMAX;
	cache[2] = 2;
	cache[3] = 4;

	int T;
	scanf("%d", &T);
	
	while(T--){
		int N, M;
		scanf("%d", &N);

		for(int i = 4; i <= N; i ++){
			int tmp = cache[i-1] + 2;
			
			for(int j = 1; j*j <= i; j ++){
				if(i % j != 0) continue;
				
				int div = cache[i/j] + cache[j];
				if(div < tmp){
					tmp = div;
					pcache[i][0] = i/j;
					pcache[i][1] = j;
				}
			}
			cache[i] = tmp;
		}
		
		printf("[%d] %d*%d\n", cache[N], pcache[N][0], pcache[N][1]);
	}
	return 0;
}
