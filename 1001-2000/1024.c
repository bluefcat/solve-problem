#include <stdio.h>

int main(){
	int N, L;
	scanf("%d %d", &N, &L);

	int l = 0;
	int max = 0, min = 0;
	for(l = L; l <= 100; l ++){
		max = ((N<<1) + L*(L+1))/(L+1);
		max >>= 1;
		min = ((N<<1) - L*(L+1))/(L+1);
		min >>= 1;
		
		int sum = 0;
		for(int i = min; i <= max; i ++){
			sum += i;
		}

		if (sum == N){
			break;
		}

		if(l == 100){
			printf("-1\n");
			return 0;
		}
	}

	if(l > 100){
		printf("-1\n");
		return 0;
	}

	for(int i = min; i <= max; i ++){
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
