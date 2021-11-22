#include <stdio.h>

int mpow(int p, int q, int N){
	if(q == 0) return 1;
	if(q == 1) return p % N;

	if(q & 1) return (p * mpow(p, q-1, N)) % N;

	int half = mpow(p, q >> 1, N) % N;

	return (half * half) % N;
}

int main(){
	int t, a, b;
	
	scanf("%d", &t);

	for(int i = 0; i < t; i ++){
		scanf("%d %d", &a, &b);
		int result = mpow(a, b, 10);
		printf("%d\n", result == 0 ? 10: result);

	}
	return 0;
}
