#include <stdio.h>
#define MAX 100

int main(){
	int white_paper[MAX][MAX];

	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++)
			white_paper[i][j] = 0;

	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);

		for(int dw = 0; dw < 10; dw ++)
			for(int dh = 0; dh < 10; dh ++) 
				white_paper[x+dw][y+dh] = 1;
	}

	int result = 0;

	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++) 
			result += white_paper[i][j];

	printf("%d\n", result);

	return 0;
}
