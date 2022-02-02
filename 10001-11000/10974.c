#include <stdio.h>

int n;
int s[9];
int v[9];

void permutation(int d){
	if(d == n){
		for(int i = 0; i < n; i ++) printf("%d ", s[i]);
		printf("\n");
	}
	
	for(int i = 1; i <= n; i ++){
		if(v[i] == 0){
			v[i] = 1; s[d] = i;
			permutation(d+1);
			v[i] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	
	permutation(0);
	
	return 0;
}
