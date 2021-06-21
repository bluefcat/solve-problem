#include <stdio.h>
#include <stdlib.h>

#define MAXITEM 101
#define MAXCOST 10001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int cache[MAXITEM][MAXCOST];
int apps[MAXITEM][2];

int compare(const void* a, const void* b){
	int* n1 = (int*)a;
	int* n2 = (int*)b;

	int result = n1[1]-n2[1];
	if(result == 0){
		return n1[0]-n2[0];
	}
	return result;
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	apps[0][0] = 0;
	apps[0][1] = 0;

	for(int i = 1; i <= n; i ++){
		scanf("%d", apps[i]);
	}

	for(int i = 1; i <= n; i ++){
		scanf("%d", apps[i] + 1);
	}

	qsort(apps, n+1, 2*sizeof(int), compare);

	int result = 100000;
	for(int a = 1; a <= n; a ++){
		int memory = apps[a][0];
		int cost = apps[a][1];
		
		for(int c = 0; c < MAXCOST; c++){
			if(c >= cost){
				cache[a][c] = MAX(memory, cache[a-1][c]);
				cache[a][c] = MAX(cache[a][c], cache[a-1][c-cost] + memory);
			}
			else{
				cache[a][c] = cache[a-1][c];
			}

		}
	}

	
	for(int a = 0; a <= n; a ++){
		for(int c = 0; c < MAXCOST; c++){
			if(cache[a][c] >= m){
				result = (result < c)? result: c;
			}
		}
	}

	printf("%d\n", result);


	return 0;
}
