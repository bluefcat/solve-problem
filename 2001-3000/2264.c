#include <stdio.h>
#include <stdlib.h>


typedef struct point_{
	int x;
	int y;
} point;

int compare(const void* x, const void* y){
	return ((point*)x)->x - ((point*)y)->x;
}

point p[100000];
int n;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d %d", &(p[i].x), &(p[i].y));

	qsort(p, n, sizeof(point), compare);
	
	for(int i = 0; i < n; i ++){
		printf("%d %d\n", p[i].x, p[i].y);
	}

	return 0;
}
