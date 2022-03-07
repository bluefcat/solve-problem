#include <stdio.h>
#include <limits.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define ABS(X) (((X) > 0)? (X): -(X))
int map[501][501];

int n, m, b, result = INT_MAX, mheight = 0, height = 0;

int main(){
	scanf("%d %d %d", &n, &m, &b);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			scanf("%d", map[i]+j);
			mheight = MAX(mheight, map[i][j]);
		}
	}
	

	//sovle
	
	for(int t = 0; t <= mheight; t ++){
		// idx
		// 0 : delete
		// 1 : create
		int r[2] = { 0, };

		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				int tmp = t - map[i][j];
				
				if(tmp < 0) r[0] += ABS(tmp);
				else r[1] += ABS(tmp);
			}
		}

		if(r[0] + b >= r[1]){
			int time = r[0]*2 + r[1];
			
			if(result > time){
				result = time;
				height = t;
			}

		}

	}

	printf("%d %d\n", result, height);
	return 0;
}
