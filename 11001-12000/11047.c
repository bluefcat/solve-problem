#include <stdio.h>

int coin[10];

int main(){
	int n, k, result = 0;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i ++){
		scanf("%d", coin+i);
	}


	for(int i = n-1; i >= 0 && k; i --){
		int count = k/coin[i];

		k -= count*coin[i];
		result += count;
	}

	printf("%d\n", result);

	return 0;
}
