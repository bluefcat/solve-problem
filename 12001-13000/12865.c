#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

#define MAX_COUNT 101
#define MAX_CAPACITY 100001
//cache memoried the value of the goods in bag
int cache[MAX_COUNT][MAX_CAPACITY];

int compare(const void* x, const void* y){
	return ((int*)x)[0] > ((int*)y)[0];
}

int main(){
	int n, k, result = 0;
	//second index info
	//0 is the weight of the good
	//1 is the value of the good
	int items[101][2];
	scanf("%d %d", &n, &k);

	items[0][0] = 0; items[0][1] = 0;

	for(int i = 1; i <= n; i ++){
		scanf("%d %d", items[i]+0, items[i]+1);
	}

	qsort(items, n+1, sizeof(int)*2, compare);

	for(int i = 1; i <= n; i ++){
		int iw = items[i][0], iv = items[i][1];
		for(int c = 0; c < MAX_CAPACITY; c ++){
			
			if(c >= iw){
				cache[i][c] = MAX(cache[i-1][c-iw]+iv, iv);
				cache[i][c] = MAX(cache[i][c], cache[i-1][c]);
			}
			else {
				cache[i][c] = cache[i-1][c];
			}
		}
	}

	result = cache[n][k];
	printf("%d\n", result);

	return 0;
}
