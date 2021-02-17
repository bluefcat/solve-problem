#include <stdio.h>

long long mem[100][10];

int main(){
	mem[0][0] = 0;
	for(int i = 1; i < 10; i ++){
		mem[0][i] = 1;
	}	
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < n; i ++){
		mem[i][0] = mem[i-1][1] % 1000000000;
		mem[i][9] = mem[i-1][8] % 1000000000;
		for(int j = 1; j < 9; j ++){
			mem[i][j] = (mem[i-1][j-1]+mem[i-1][j+1]) % 1000000000;	
		}
	}
	
	long long result = 0;
	for(int i = 0; i < 10; i ++){
		result += mem[n-1][i];
	}
	
	result %= 1000000000;

	printf("%lld\n", result);

	return 0;
}
