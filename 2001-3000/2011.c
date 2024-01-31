#include <stdio.h>
#include <string.h>

#define MOD 1000000
char x[5001];
int cache[5001][5001];

int solve(int s, int e){
	if(cache[s][e] != -1) return cache[s][e];
	if(e - s == 0) return 0;
	else if(e - s == 1){
		return (x[s] != '0');
	}
	else if(e - s == 2){
		if(x[s] == '1' && x[s+1] == '0') 
			return 1;
		if(x[s] == '1' && x[s+1] != '0') 
			return 2;
		if(x[s] == '2' && x[s+1] == '0')
			return 1;
		if(x[s] == '2' && x[s+1] < '7') 
			return 2;
	}
	int result = (solve(s, s+1) * solve(s+1, e)) % MOD;

	if(x[s] == '1' || (x[s] =='2' && x[s+1] < '7')) 
		result = (result + solve(s+2, e)) % MOD;
	
	cache[s][e] = result;
	return result;
}

int main(){
	for(int i = 0; i < 5001; i ++)
		for(int j = 0; j < 5001; j ++) cache[i][j] = -1;
	scanf("%s", x);
	//for(int i = 0; i < 5000; i ++) x[i] = '1';
	printf("%d\n", solve(0, strlen(x)));
	return 0;
}
