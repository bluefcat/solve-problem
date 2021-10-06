#include <stdio.h>

int main(){
	int cand_x[1001] = { 0, };
	int cand_y[1001] = { 0, };

	for(int i = 0; i < 3; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		
		cand_x[x] ++;
		cand_y[y] ++;
	}

	int x = 0, y = 0;
	
	for(int i = 0; i < 1001; i ++){
		if(cand_x[i] == 1) x = i;
		if(cand_y[i] == 1) y = i;
	}

	printf("%d %d\n", x, y);

	return 0;
}
