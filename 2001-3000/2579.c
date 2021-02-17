#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int stair[301];
int cache[301];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", stair+i);
	}
	
	cache[0] = stair[0];
	cache[1] = MAX(stair[0]+stair[1], stair[1]);
	cache[2] = MAX(stair[0]+stair[2], stair[1]+stair[2]);

	for(int i = 3; i < n; i ++){
		cache[i] = MAX(cache[i-2]+stair[i], cache[i-3]+stair[i-1]+stair[i]);
	}

	printf("%d\n", cache[n-1]);
	return 0;
}
