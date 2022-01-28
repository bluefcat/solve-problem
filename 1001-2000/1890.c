#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

long long map[102][102];
long long cache[102][102];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++) scanf("%lld", map[i]+j);
	
	cache[0][0] = 1;

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(!cache[i][j] || !map[i][j]) continue;
			
			long long count = map[i][j];

			if(0 <= j+count && j+count < n) cache[i][j+count] += cache[i][j];
			if(0 <= i+count && i+count < n) cache[i+count][j] += cache[i][j];
		}
	}

	printf("%lld\n", cache[n-1][n-1]);

	return 0;
}
