#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int cache[100001];
int solve(int l, int r){
	int result = 0;
	
	int height = cache[l];
	int m = l;
	for(int i = l+1; i < r; i ++){
		if(height > cache[i]){
			height = cache[i];
			m = i;
		}
	}

	result = height*(r-l);

	if(l < m) result = MAX(result, solve(l, m));
	if(m+1 < r) result = MAX(result, solve(m+1, r));

	return result;
}


int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
		for(int i = 0; i < n; i ++) scanf("%d", cache + i);
		
		int result = solve(0, n);
		
		printf("%d\n", result);
	}
	

	return 0;
}
