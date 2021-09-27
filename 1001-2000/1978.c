#include <stdio.h>

int mpow(int b, int e, int N){
	if(e == 0) return 1;
	if(e & 1) return (mpow(b, e-1, N) * b) % N;

	int h = mpow(b, e >> 1, N) % N;

	return (h * h) % N;
}

int main(){
	int result = 0;
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i ++){
		int x;
		scanf("%d", &x);
		if(x == 1) goto NOPRIME;

		for(int a = 1; a < x; a ++){
			if(mpow(a, x-1, x) != 1){
				goto NOPRIME;	
			}
		}

		PRIME:
		result ++;
		
		NOPRIME:
		continue;
	}

	printf("%d\n", result);

	return 0;
}
