#include <stdio.h>

char p[3][6] = {
 "  *  ",
 " * * ",
 "*****"
};

char result[6500][6500];

void draw_tri(int n, int x, int y){
	if(n == 1){
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j < 5; j ++){
				result[x+i][y+j] = p[i][j];
			}
		}
		return;
	}

	draw_tri(n/2, x, y+3*n/2);
	
	draw_tri(n/2, x+3*n/2, y);
	draw_tri(n/2, x+3*n/2, y+3*n);
}

int main(){
	int n = 0;
	scanf("%d", &n);

	draw_tri(n/3, 0, 0);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < 2*n-1;j++) printf("%c", result[i][j] == '*' ? '*': ' ');
		printf("\n");
	}

	return 0;
}
