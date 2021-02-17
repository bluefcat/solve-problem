#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int main(){
	int a[1001] = { 0, };
	int cache[1001] = { 0, };
	for(int i = 0; i < 1000; i ++) cache[i] = 1;

	int n, result = 1;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", a+i);
		
		for(int j = 0; j < i; j ++){
			if(a[j] < a[i]) cache[i] = MAX(cache[i], cache[j]+1);
		}

		result = MAX(result, cache[i]);
	}

	printf("%d\n", result);

	return 0;
}
