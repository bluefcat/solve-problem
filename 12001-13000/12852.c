#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int cache[1000001];

int main(){
	int n, result = 0;
	
	scanf("%d", &n);
	
	cache[2] = 1;
	cache[3] = 1;

	for(int i = 4; i <= n; i ++){
		cache[i] = cache[i-1]+1;
		if(i % 3 == 0) cache[i] = MIN(cache[i], cache[i/3]+1);
		if(i % 2 == 0) cache[i] = MIN(cache[i], cache[i>>1]+1);
	}

	printf("%d\n", cache[n]);
	
	int target = n;

	while(target != 1){
		printf("%d ", target);
		int x = cache[target];

		if(target % 3 == 0 && x-1 == cache[target/3]){
			target /= 3;
		}

		else if(target % 2 == 0 && x-1 == cache[target>>1]){
			target >>= 1;
		}
		
		else{
			target --;
		}

	}

	printf("%d\n", target);

	return 0;
}
