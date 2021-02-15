#include <stdio.h>

int main(){
	int n;
	int mem[3] = { 1, 1, 2 };
	scanf("%d", &n);
	
	for(int i = 0; i <= n; i ++){
		mem[(i+2)%3] = mem[(i+1)%3] + mem[i%3];
		mem[(i+2)%3] %= 15746;
	}

	printf("%d\n", mem[n%3]);	
	return 0;
}
