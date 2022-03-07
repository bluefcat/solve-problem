#include <stdio.h>

int den(int N, int L){
	return (N << 1) - L * (L + 1);
}

int num(int L){
	return L << 1;
}

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	
	int init = -1;
	for(L; L <= 100; L ++){
		int d = den(N, L);
		int n = num(L);

		if(d % n == 0){
			init = d/n;
			break;
		}
	}
	
	if( 1 + init < 0 || L > 100 ){
		printf("%d\n", -1);
		return 0;
	}

	for(int i = 1; i <= L; i ++){
		printf("%d ", i+init);
	}
	printf("\n");

	return 0;
}
