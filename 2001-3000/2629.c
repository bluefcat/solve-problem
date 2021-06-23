#include <stdio.h>
#include <math.h>

#define MAXWEIGHTS 31
#define MAXMARBLE 40001

int cache[MAXWEIGHTS][MAXMARBLE];
int weights[MAXWEIGHTS];
int marbles[MAXMARBLE];

int main(){
	int w = 0, m = 0;

	scanf("%d", &w);
	for(int i = 1; i <= w; i ++) scanf("%d", weights+i);

	scanf("%d", &m);
	for(int i = 1; i <= m; i ++) scanf("%d", marbles+i);
	
	cache[0][0] = 1;
	for(int i = 1; i <= w; i ++){
		int weight = weights[i];
		cache[i][0] = 1;
		
		for(int j = 1; j < MAXMARBLE; j ++){
			cache[i][j] = cache[i-1][j] || cache[i-1][abs(j-weight)];
			if(j + w < MAXMARBLE) cache[i][j] = cache[i][j] || cache[i - 1][j + weight];
		}
	}
	
	for(int i = 1; i <= m; i ++){
		if(cache[w][marbles[i]] != 0){
			printf("Y ");
		}
		else{
			printf("N ");
		}
	}
	
	printf("\n");
	return 0;
}
