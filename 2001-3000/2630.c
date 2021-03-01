#include <stdio.h>

int field[128][128];
int white, blue;

void count_tile(int x, int y, int n){
	int flag = field[x][y];
	if(n == 1){
		if(flag) blue ++;
		else white ++;
		return;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(flag != field[x+i][y+j]) goto PART;
		}
	}
	
	if(flag) blue ++;
	else white ++;
	goto EXIT;

	PART:
	count_tile(x, y, n/2);
	count_tile(x+n/2, y, n/2);
	count_tile(x, y+n/2, n/2);
	count_tile(x+n/2, y+n/2, n/2);
	
	EXIT:
	return ;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%d", field[i]+j);
		}
	}

	count_tile(0, 0, n);

	printf("%d\n%d\n", white, blue);
	return 0;
}
