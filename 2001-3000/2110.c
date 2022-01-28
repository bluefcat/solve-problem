#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[200001];
int n, c;

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

int main(){
	scanf("%d %d", &n, &c);

	for(int i = 0; i < n; i ++) scanf("%d", map+i);

	qsort(map, n, sizeof(int), compare);

	
	int start = 1;
	int end = map[n-1] - map[0];
	
	int result = 0;
	
	while(start <= end){
		int mid = (start+end) >> 1;

		int count = 1;

		int prev = map[0];

		for(int i = 1; i < n; i ++){
			if(map[i] - prev >= mid){
				count ++;
				prev = map[i];
			}
		}

		if(count >= c){
			result = MAX(result, mid);
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}

	printf("%d\n", result);

	return 0;
}
