#include <stdio.h>
#include <stdlib.h>
#define MAXPEOPLE 21
#define MAXHP 101
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
// idx 0's about lost healthy point
// idx 1's about get happy point
int P[MAXPEOPLE][2];
int cache[MAXPEOPLE][MAXHP];

int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int N, result = 0;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i ++){
		scanf("%d", P[i]);
	}

	for(int i = 1; i <= N; i ++){
		scanf("%d", P[i]+1);
	}

	qsort(P, N+1, sizeof(int)*2, compare);

	for(int i = 1; i <= N; i ++){
		int lost = P[i][0], happy = P[i][1];
		
		for(int hp = 0; hp < MAXHP; hp ++){
			if(hp > lost){
				cache[i][hp] = MAX(happy, cache[i-1][hp]);
				cache[i][hp] = MAX(cache[i][hp], cache[i-1][hp-lost] + happy);
			}
			else{
				cache[i][hp] = cache[i-1][hp];
			}

			result = MAX(result, cache[i][hp]);
		}
	}

	printf("%d\n", result);

	return 0;
}
