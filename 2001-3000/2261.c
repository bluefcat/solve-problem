#include <stdio.h>
#define DIST(X, Y) ((X)*(X) + (Y)*(Y))

int n;
int cache[100001][2];

void swap(int* x, int* y){
	int a = x[0]; 
	int b = x[1];
	
	x[0] = y[0]; 
	x[1] = y[1];
	
	y[0] = a; 
	y[1] = b;
}

int partition(int l, int r){
	int pivot[2] = { cache[r-1][0], cache[r-1][1] };
	

	int pidx = r-1;
	int c = l;

	for(int i = l; i < pidx; i ++){
		if(pivot[0] > cache[i][0]){
			swap(cache[c], cache[i]);
			c ++;
		}
		else if(pivot[0] == cache[i][0] && pivot[1] > cache[i][1]){
			swap(cache[c], cache[i]);
			c ++;
		}
	}
	
	swap(cache[pidx], cache[c]);
	return c;
}

void quicksort(int l, int r){
	if(l+1 >= r) return;

	int pidx = partition(l, r);
	quicksort(l, pidx);
	quicksort(pidx+1, r);
}


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d %d", cache[i]+0, cache[i]+1);
	}

	quicksort(0, n);
	
	printf("===\n");
	for(int i = 0; i < n; i ++){
		printf("%d %d\n", cache[i][0], cache[i][1]);
	}

	return 0;
}
