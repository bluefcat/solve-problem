#include <stdio.h>
#include <limits.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int cache[501][501];

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		int result = INT_MAX;
		scanf("%d", &n);

		for(int x = 1; x <= n; x ++){
			scanf("%d", cache[x]+x);
			
			for(int d = 1; d < x; d ++){
				int y = x - d;
				cache[x][y] = INT_MAX;	
				
				int t = d + 1;
				for(int i = 1; i <= d; i ++){
					cache[x][y] = MIN(cache[x][y+(t-i)] + cache[x-i][y], cache[x][y]);
				}
			}
		}

		for(int i = 0; i <= n; i ++){
			for(int j = 0; j <= n; j ++) printf("%10d\t", cache[i][j]);
			printf("\n");
		}

	}


	return 0;
}
