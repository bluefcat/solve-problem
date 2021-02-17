#include <stdio.h>
#include <math.h>

int binomial[11][11];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	binomial[0][0] = 1;
	for(int i = 1; i < 11; i ++){
		for(int j = 0; j <= i; j ++){
			if(j == 0 || j == i){
				binomial[i][j] = 1;
			}
			else{
				binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
			}
		}
	}

	printf("%d\n", binomial[n][k]);
	return 0;
}
