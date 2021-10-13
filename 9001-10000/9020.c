#include <stdio.h>
#include <math.h>

#define MAXLEN 10001

int cache[MAXLEN];

int main(){
	
	for(int i = 2; i <= sqrt(MAXLEN); i ++){
		if(cache[i] == 0){
			for(int j = 2; i*j <= MAXLEN; j ++) cache[i*j] = 1;
		}
	}

	
	int t;
	scanf("%d", &t);
	
	for(int n = 0; n < t; n ++){
		int x;
		scanf("%d", &x);
		
		for(int i = x >> 1; i > 0; i --){
			if(cache[i] == 0 && cache[x-i] == 0){
				printf("%d %d\n", i, x-i);
				break;
			}
		}

	}

	return 0;
}

