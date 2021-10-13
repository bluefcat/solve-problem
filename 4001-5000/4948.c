#include <stdio.h>
#include <math.h>

#define MAXLEN 123456*2+1

int cache[MAXLEN];

int main(){
	
	for(int i = 2; i <= sqrt(MAXLEN); i ++){
		if(cache[i] == 0){
			for(int j = 2; i*j <= MAXLEN; j ++) cache[i*j] = 1;
		}
	}

	
	int n;
	while(scanf("%d", &n) && n != 0){
		int result = 0;
		
		for(int i = n+1; i <= 2*n; i ++){
			if(cache[i] == 0) result ++;
		}

		printf("%d\n", result);

	}
	
	return 0;
}
