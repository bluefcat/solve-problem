#include <stdio.h>

int apart[15][15];

int main(){
	for(int i = 0; i < 15; i ++){
		for(int j = 1; j < 15; j ++){
			if(i == 0){
				apart[i][j] = j;
				continue;
			}
			for(int k = 1; k <= j; k ++) apart[i][j] += apart[i-1][k];
		}
	}


	int t = 0, k = 0, n = 0;
	scanf("%d", &t);
	for(int i = 0; i < t; i ++){
		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", apart[k][n]);
	}
	return 0;
}
