#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))?(X): (Y))
typedef struct line_{
	int x;
	int y;
} line;

line cache[1000001];

void swap(int x, int y){
	line tmp = (line){ cache[x].x, cache[x].y };
	
	cache[x].x = cache[y].x;
	cache[x].y = cache[y].y;

	cache[y].x = tmp.x;
	cache[y].y = tmp.y;
}

int partition(int l, int r){
	int pidx = r-1;
	int pivot = cache[pidx].x;
	
	int c = l;
	for(int i = l; i < pidx; i ++){
		if(pivot > cache[i].x){
			swap(i, c);
			c++;
		}
	}
	
	swap(c, pidx);
	return c;
}

void quicksort(int l, int r){
	if(l+1 >= r) return;
	int pidx = partition(l, r);
	quicksort(l, pidx);
	quicksort(pidx+1, r);
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		cache[i].x = x; cache[i].y = y;
	}
	
	quicksort(0, n);
	
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
