#include <stdio.h>

int map[1026][1026];

int main(){
	int n, m;
	
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			scanf("%d", map[i]+j);
			if(j > 1) map[i][j] += map[i][j-1];
		}
	}

	for(int i = 2; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			map[i][j] += map[i-1][j];
		}
	}

	for(int i = 0; i < m; i ++){
		int x1, y1, x2, y2, result = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 -= 1; y1 -= 1;
		

		result = map[x2][y2] + map[x1][y1] - (map[x1][y2] + map[x2][y1]);
		printf("%d\n", result);

	}


	return 0;
}
