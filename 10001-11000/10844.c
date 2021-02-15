#include <stdio.h>

int mem[100];

int main(){
	mem[0] = 9;
	
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < n; i ++){
		mem[i] = mem[i-1]*2-1;
		mem[i] %= 1000000000;
	}

	printf("%d\n", mem[n-1]);

	return 0;
}
