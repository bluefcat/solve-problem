#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int main(){
	int n;
	int result = 0;
	int cache[30001] = { 0, };

	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", cache+i);
	
	for(int t = 0; t < n; t ++){
		int tmp = 0;
		for(int f = t + 1; f < n && cache[t] >= cache[f]; f ++) tmp ++;
		result = MAX(result, tmp);

	}

	printf("%d\n", result);

	return 0;
}
