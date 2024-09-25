#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y))?(X): (Y))

typedef struct line_{
	int x;
	int y;
} line;

line cache[1000001];

int compare(const void* p, const void* q){
	return ((const line*)p)->x > ((const line*)q)->x;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		cache[i].x = x; cache[i].y = y;
	}
	
	qsort(cache, n, sizeof(line), compare);
	
	int l = 0, r = 0, result = 0;
	for(int i = 0; i < n; i ++){
		if(i == 0){
			l = cache[i].x; 
			r = cache[i].y;
		}
		
		else if(l <= cache[i].x && cache[i].x <= r){
			r = MAX(r, cache[i].y);
		}
		else{
			result += r-l;
			l = cache[i].x; 
			r = cache[i].y;
		}
	}
	
	result += r-l;

	printf("%d\n", result);

	return 0;
}
