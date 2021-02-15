#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int tri[501][501];

int main(){
	int result = 0;
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j <= i; j ++){
			scanf("%d", tri[i]+j);
		}
	}

	for(int i = 0; i < n-1; i ++){
		for(int j = 0; j <= i+1; j ++){
			int l = j;
			int r = (j == 0)? 0: j-1;

			tri[i+1][j] += MAX(tri[i][l], tri[i][r]);
		}
	}
	

	for(int i = 0; i < n; i ++){
		if(result < tri[n-1][i]) result = tri[n-1][i];
	}

	printf("%d\n", result);
	return 0;
}
