#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int cache[100001];

int main(){
	int n, k, result = 0, tmp = 0;
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i ++) scanf("%d", cache+i);
	for(int i = 0; i < k; i ++) tmp += cache[i];
	
	result = tmp;
	
	for(int i = 0; i < n-k; i ++){
		tmp = tmp - cache[i] + cache[k+i];
		result = MAX(result, tmp);
	}

	printf("%d\n", result);

	return 0;
}
