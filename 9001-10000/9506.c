#include <stdio.h>
#define MAX 100000

int factorize(int n, int* result){
	int idx = 0;
	for(int i = 1; i < n; i ++){
		if(n % i == 0){
			result[idx++] = i;
		}
	}

	return idx;
}


int main(){
	int result[MAX] = { 0, };
	int n = 0;
	while(scanf("%d", &n) && n != -1){
		int m = factorize(n, result);
		
		int sum = 0;
		for(int i = 0; i < m; i ++) sum += result[i];

		if(sum == n){
			printf("%d = %d", n, result[0]);
			for(int i = 1; i < m; i ++){
				printf(" + %d", result[i]);
			}
			printf("\n");
		}
		else{
			printf("%d is NOT perfect.\n", n);
		}
	}
	
	return 0;
}
