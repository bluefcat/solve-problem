#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

#define MAXN 1002
#define MAXP 10002

int pack[MAXP];
int cache[MAXN][MAXP];


int main(){
	int n, result = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i ++) scanf("%d", pack+i);
	
	for(int lim = 1; lim <= n; lim ++){
		
		for(int i = 1; i <= lim; i ++){
			cache[lim][i] = MAX(cache[lim-1][i], pack[i]);
			
			for(int m = 1; m <= lim; m ++){
				cache[lim][i] = MAX(cache[lim][i], cache[lim-i][m] + pack[i]);
			}
		}
	}

	for(int i = 1; i <= n; i ++) result = MAX(result, cache[n][i]);

	printf("%d\n", result);

	return 0;
}
