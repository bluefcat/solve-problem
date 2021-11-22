#include <stdio.h>

int cache[301][301];

int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++) scanf("%d", cache[i]+j);
	}

	scanf("%d", &k);
	for(int n = 0; n < k; n ++){
		int i, j, x, y, result = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		
		i --; j --; x --; y --;

		for(int p = 0; p <= x-i; p ++){
			for(int q = 0; q <= y-j; q ++){
				result += cache[i+p][j+q];
			}
		}

		printf("%d\n", result);
		
	}


	return 0;
}
