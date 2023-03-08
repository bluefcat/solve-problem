#include <stdio.h>
#include <string.h>
#define MAX 22
#define TOCHAR(n) '0'+n


void solve(int x, int n, int m, int r, char* result, int i){
	if(x > n){
		if(r+m == 0) printf("%s\n", result); 
		return;
	}

	result[i] = ' ';
	result[i+1] = TOCHAR(x);
	if(m > 0) solve(x+1, n, m*10+x, r, result, i+2);
	else solve(x+1, n, m*10-x, r, result, i+2);

	result[i] = '+';
	result[i+1] = TOCHAR(x);
	solve(x+1, n, x, r+m, result, i+2);
	
	result[i] = '-';
	result[i+1] = TOCHAR(x);
	solve(x+1, n, -x, r+m, result, i+2);
	
}

int main(){
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i ++){
		scanf("%d", &n);
		char result[MAX] = { 0, }; 
		result[0] = '1';
		solve(2, n, 1, 0, result, 1);
		
		printf("\n");
	}

	return 0;
}
