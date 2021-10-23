#include <stdio.h>

#define ODD(N) 2*(N)+3

int cache[1001];

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	//init
	

	for(int i = 0; i < N; i ++) cache[i] = 1;
	
	//mark sieve
	for(int i = 0; i < N; i ++){
		K --;
		if(cache[i]){
			for(int step = i + ODD(i); step < N; step += ODD(i)){
				cache[step] = 0;
				K --;
				if(K == 0){
					result = step;
					break;
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
