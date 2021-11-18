#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int cache[10201];
int set[10201];
int n;

int pos(int x, int y){
	return x * n + y;
}

int get_parent(int x){
	if(set[x] == x) return x;

	return set[x] = get_parent(set[x]);
}

void union_set(int x, int y){
	x = get_parent(x);
	y = get_parent(y);

	if(x > y) set[y] = x;
	else set[x] = y;
}


int main(){
	int result = 0;
	int high = 0;
	
	int xp[4] = {  1,  0, -1,  0 };
	int yp[4] = {  0,  1,  0, -1 };
	scanf("%d", &n);

	for(int i = 0; i < n*n; i ++){
		scanf("%d", cache+i);
		high = MAX(high, cache[i]);
	}
	
	for(int r = 0; r <= high; r ++){
		//init set
		for(int i = 0; i < n*n; i ++) set[i] = cache[i] <= r? -1: i;
		
		//calculate
		for(int x = 0; x < n; x ++){
			for(int y = 0; y < n; y ++){
				
				if(set[pos(x, y)] == -1) continue;
				for(int i = 0; i < 4; i ++){
					int tx = x + xp[i];
					int ty = y + yp[i];

					if(tx < 0 || n <= tx) continue;
					if(ty < 0 || n <= ty) continue;
					

					int p = pos(tx, ty);
					if(set[p] == -1) continue;
					union_set(pos(x, y), p);
				}		
			}
		}

		int count = 0;
		for(int i = 0; i < n*n; i ++){
			if(set[i] == i) count ++;
		}

		result = MAX(result, count);
	}
	
	printf("%d\n", result);

	return 0;
}
