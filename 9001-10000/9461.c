#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i ++){
		long long mem[4] = { 0, 1, 1, 1 };
		int n;
		scanf("%d", &n);

		for(int i = 0; i <= n-3; i ++){
			mem[(i+3)%4] = mem[(i+1)%4] + mem[i%4];
		}
		
		printf("%lld\n", mem[n%4]);
	}
	return 0;
}
