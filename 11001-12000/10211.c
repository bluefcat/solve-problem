#include <stdio.h>
#include <limits.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int array[1002];
int cache[1002];

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", array+i);


		int result = INT_MIN;

		for(int i = 1; i <= n; i ++){
			cache[i] = MAX(array[i], array[i] + cache[i-1]);
			result = MAX(result, cache[i]);
		}

		printf("%d\n", result);
	}

	return 0;
}
