#include <stdio.h>
#include <limits.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int min_result = INT_MAX, max_result = INT_MIN;

int n, input;
int cache[2][2][3];


int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < 3; i ++){
		scanf("%d", &input);
		cache[0][0][i] = input; cache[1][0][i] = input;
	}
	for(int i = 1; i < n; i ++){
		
		scanf("%d", &input);
		cache[0][i%2][0] = MIN(cache[0][(i-1)%2][0], cache[0][(i-1)%2][1]) + input;
		cache[1][i%2][0] = MAX(cache[1][(i-1)%2][0], cache[1][(i-1)%2][1]) + input;

		scanf("%d", &input);
		cache[0][i%2][1] = MIN(cache[0][(i-1)%2][0], cache[0][(i-1)%2][1]);
		cache[0][i%2][1] = MIN(cache[0][i%2][1], cache[0][(i-1)%2][2]) + input;
		
		cache[1][i%2][1] = MAX(cache[1][(i-1)%2][0], cache[1][(i-1)%2][1]);
		cache[1][i%2][1] = MAX(cache[1][i%2][1], cache[1][(i-1)%2][2]) + input;

		scanf("%d", &input);
		cache[0][i%2][2] = MIN(cache[0][(i-1)%2][1], cache[0][(i-1)%2][2]) + input;
		cache[1][i%2][2] = MAX(cache[1][(i-1)%2][1], cache[1][(i-1)%2][2]) + input;
	}

	
	for(int i = 0; i < 3; i ++){
		min_result = MIN(min_result, cache[0][(n-1)%2][i]);
		max_result = MAX(max_result, cache[1][(n-1)%2][i]);
	}

	printf("%d %d\n", max_result, min_result);


	return 0;
}
