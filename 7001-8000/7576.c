#include <stdio.h>
#define M 1001

typedef struct pos_{
	int x;
	int y;
	int t;
} pos;

char box[M][M];
int days;

pos queue[M*M];
int q_count, q_cursor, q_size;

void ripe(int x, int y, int t){
	if(box[y][x] != 0) return;
	box[y][x] = 1;
	queue[q_count ++] = (pos){x, y, t+1};
	return;
}

int main(){
	int m, n, result = 0;
	scanf("%d %d", &m, &n);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			scanf("%hhd", box[i] + j);
			if(box[i][j] == 1) queue[q_count++] = (pos){ j, i, days };	

		}
	}

	while(q_cursor < q_count){
		int x = queue[q_cursor].x, y = queue[q_cursor].y, t = queue[q_cursor].t;
		
		result = t > result? t: result;

		if(0 <= x-1) ripe(x-1, y, t);
		if(x+1 < m) ripe(x+1, y, t);
		if(0 <= y-1) ripe(x, y-1, t);
		if(y+1 < n) ripe(x, y+1, t);

		q_cursor ++;
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++) if(box[i][j] == 0) result = -1; 
	}

	printf("%d\n", result);

	return 0;
}
