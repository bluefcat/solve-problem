#include <stdio.h>

int main(){
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	for(int i = 1; i <= n; i ++){
		printf("[%d %d]\n", i*i, i*n); 
	}

	return 0;
}
