#include <stdio.h>

int field[2187][2187];
int pos, zero, neg;

void count_tile(int x, int y, int n){
	int flag = field[x][y];
	
	if(n == 1){
		if(flag == 1) pos ++;
		else if(flag == 0) zero ++;
		else neg ++;
		return;
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(flag != field[x+i][y+j]) goto PART;
		}
	}
	
	if(flag == 1) pos ++;
	else if(flag == 0) zero ++;
	else neg ++;
	goto EXIT;

	PART:
	count_tile(x, y, n/3);
	count_tile(x+n/3, y, n/3);
	count_tile(x+2*n/3, y, n/3);
	count_tile(x, y+n/3, n/3);
	count_tile(x+n/3, y+n/3, n/3);
	count_tile(x+2*n/3, y+n/3, n/3);
	count_tile(x, y+2*n/3, n/3);
	count_tile(x+n/3, y+2*n/3, n/3);
	count_tile(x+2*n/3, y+2*n/3, n/3);
	
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

	printf("%d\n%d\n%d\n", neg, zero, pos);
	return 0;
}
