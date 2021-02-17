#include <stdio.h>

int combination[30][30];

int main(){
	int T;
	scanf("%d", &T);

	combination[0][0] = 1;
	for(int i = 1; i < 30; i ++){
		for(int j = 0; j <= i; j ++){
			if(j == 0 || j == i){
				combination[i][j] = 1;
			}
			else {
				combination[i][j] = combination[i-1][j-1]+combination[i-1][j];
			}
		}
	}

	for(int i = 0; i < T; i ++){
		int x, y, result = 0;
		scanf("%d %d", &x, &y);

		result = combination[y][x];

		printf("%d\n", result);
	}
	

	return 0;
}
