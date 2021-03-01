#include <stdio.h>

int field[64][64];

void count_tile(int x, int y, int n){
	int flag = field[x][y];
	if(n == 1){
		printf("%d", flag);
		return;
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(flag != field[x+i][y+j]) goto PART;
		}
	}
	
	printf("%d", flag);
	goto EXIT;

	PART:
	printf("(");
	count_tile(x, y, n/2);
	count_tile(x, y+n/2, n/2);
	count_tile(x+n/2, y, n/2);
	count_tile(x+n/2, y+n/2, n/2);
	printf(")");

	EXIT:
	return ;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		char tmp[65];
		scanf("%s", tmp);
		char* p = tmp;
		while(*p){
			field[i][(p-tmp)/sizeof(char)] = (*p)-'0';
			p ++;
		}
	}

	count_tile(0, 0, n);
	printf("\n");

	return 0;
}
