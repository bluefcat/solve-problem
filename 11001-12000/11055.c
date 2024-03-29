#include <stdio.h>

#define MAXA 1001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int arr[MAXA];
int cache[MAXA];

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", arr + i);

	for(int i = 0; i < n; i ++){
		int tmp = arr[i];
		for(int j = 0; j < i; j ++){
			if(arr[i] > arr[j]){
				tmp = MAX(tmp, arr[i] + cache[j]);
			}
		}
		cache[i] = tmp;
		result = MAX(result, cache[i]);
	}

	printf("%d\n", result);
	return 0;
}
