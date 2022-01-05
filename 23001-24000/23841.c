#include <stdio.h>

int main(){
	char paint[102][52] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i ++){
		scanf("\n");
		for(int j = 0; j < m; j ++) scanf("%c", paint[i]+j);
	}

	int half = m >> 1;

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < half; j ++){
			char left = paint[i][j];
			char right = paint[i][m-(j+1)];
		
			if(left != '.') paint[i][m-(j+1)] = left;
			else if(right != '.') paint[i][j] = right;

		}
	}

	for(int i = 0; i < n; i ++){
		printf("%s\n", paint[i]);
	}
	
	return 0;
}
