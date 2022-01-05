#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int arr[1001];
int cache[1001];

int main(){
	int n, result = 0;
	scanf("%d", &n);

	for(int i = 0 ; i < n; i ++){
		scanf("%d", arr+i);
		cache[i] = 1;
	}

	for(int i = 0; i < n; i ++){
		int tmp = cache[i];
		for(int j = 0; j < i; j ++){
			if(arr[i] < arr[j]) tmp = MAX(tmp, cache[j]+1);
		}
		cache[i] = tmp;

		result = MAX(result, cache[i]);
	}

	printf("%d\n", result);


	return 0;
}
