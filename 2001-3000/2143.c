#include <stdio.h>

int cache[1002][1002];
int matrix[2][1001];

int main(){
	int t, n[2];

	scanf("%d", &t);
	
	for(int i = 0; i < 2; i ++){
		scanf("%d", n+i);
		for(int j = 0; j < n[i]; j ++) scanf("%d", matrix[i]+j);
	}
	
	printf("%d %d\n", n[0], n[1]);
	for(int i = 1; i <= n[0]; i ++) cache[i][0] = matrix[0][i-1];
	for(int i = 1; i <= n[1]; i ++) cache[0][i] = matrix[1][i-1];
	
	//col swap
	int tmp[1002] = { 0, };
	for(int i = 1; i <= n[0]; i ++) tmp[i] = cache[i][0];

	for(int i = 1; i <= n[1]; i ++){
		for(int j = 0; j <= n[0]; j ++){
			cache[j][i] += tmp[j];
			tmp[j] = cache[j][i];
		}
	}

	//row swap
	for(int i = 0; i < 1002; i ++) tmp[i] = 0;
	for(int i = 1; i <= n[1]; i ++) tmp[i] = cache[0][i];

	for(int i = 1; i <= n[0]; i ++){
		for(int j = 0; j <= n[1]; j ++){
			cache[i][j] += tmp[j];
			tmp[j] = cache[i][j];
		}
	}


	for(int i = 0; i <= n[0]; i ++){
		for(int j = 0; j <= n[1]; j ++) printf("%d\t", cache[i][j]);
		printf("\n");
	}
	
	int result = 0;

	for(int i = 0; i <= n[0]; i ++){
		for(int j = 0; j <= n[1]; j ++){
		
			for(int x = i; x <= n[0]+1; x ++){
				for(int y = j; y <= n[1]+1; y ++){
					int s = cache[x][y] - cache[x][j] - cache[i][y] + cache[i][j];
					if(s == t) printf("(%d %d ~ %d %d) %d\n", x, y, i, j, s);
				}
			}

		}
	}

	printf("%d\n", result);

	return 0;
}
