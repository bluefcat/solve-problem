#include <stdio.h>
#define MAX 10001

int main(){
	int n, m;
	int x[2][MAX] = { 0, };

	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < n * m; j ++)
			scanf("%d", x[i] + j);

	for(int i = 0; i < n * m; i ++) x[0][i] += x[1][i];

	for(int i = 0; i < n * m; i ++){
		if(i != 0 && i % m == 0) printf("\n");
		printf("%d ", x[0][i]);
	}
}
