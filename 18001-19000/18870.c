#include <stdio.h>
#include <stdlib.h>

int cache[1000000];
int cache2[1000000];
int map[1000000];

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n;
	scanf("%d", &n);

	int count = 0;
	for(int i = 0; i < n; i ++){
		int temp = 0;
		scanf("%d", &temp);

		for(int j = 0; j < n; j ++){
			if(temp == cache[j]){
				goto A;
			}
		}
		cache[count] = temp;
		count ++;

		A:
		cache2[i] = temp;
	}

	qsort(cache, count, sizeof(int), compare);
	
	for(int i = 0; i < count; i ++){
		int idx = (cache[i]+1000000000) % 1000000;
		map[idx] = i;
	}

	for(int i = 0; i < n; i ++){
		int idx = (cache2[i]+1000000000) % 1000000;
		printf("%d ", map[idx]);
	}

	printf("\n");
	
	return 0;
}
