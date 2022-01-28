#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int cache[100001];

int main(){
	int result = -1;
	int n = 0;
	scanf("%d", &n);

	cache[2] = 1;
	cache[5] = 1;

	for(int i = 2; i <= n; i ++){
		int tmp = 100001;

		if(cache[i-2] != 0) tmp = MIN(tmp, cache[i-2]+1);
		if(i >= 5) if(cache[i-5] != 0) tmp = MIN(tmp, cache[i-5]+1);
		
		if(tmp != 100001) cache[i] = tmp;

	}
	
	printf("%d\n", cache[n] != 0? cache[n]: -1);


	return 0;
}
