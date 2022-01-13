#include <stdio.h>

int app[100001][2];

int main(){
	int T;

	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d %d", app[i]+0, app[i]+1);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j) continue;

			printf("[[%d], %d], (%d, %d) < (%d, %d) %d\n", i, j, app[i][0], app[i][1], app[j][0], app[j][1],
					app[i][0] > app[j][0] || app[i][1] > app[j][1]);
		}

		printf("-----\n");
	}



	return 0;
}
