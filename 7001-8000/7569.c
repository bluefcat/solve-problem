#include <stdio.h>
#define M 101

typedef struct pos_{
	int x;
	int y;
	int z;
	int t;
} pos;

char box[M][M][M];
int days;

pos queue[M*M*M];
int q_count, q_cursor;

void ripe(int x, int y, int z, int t){
	if(box[y][x][z] != 0) return;
	box[y][x][z] = 1;
	queue[q_count ++] = (pos){x, y, z, t+1};
	return;
}

int main(){
	int m, n, h, result = 0;
	scanf("%d %d %d", &m, &n, &h);

	for(int k = 0; k < h; k ++){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
					scanf("%hhd", box[i][j] + k);
					if(box[i][j][k] == 1) queue[q_count++] = (pos){ j, i, k, days };	
			}
		}
	}

	while(q_cursor < q_count){
		int x = queue[q_cursor].x, y = queue[q_cursor].y, z = queue[q_cursor].z, t = queue[q_cursor].t;
		
		result = t > result? t: result;

		if(0 <= x-1) ripe(x-1, y, z, t);
		if(x+1 < m) ripe(x+1, y, z, t);

		if(0 <= y-1) ripe(x, y-1, z, t);
		if(y+1 < n) ripe(x, y+1, z, t);

		if(0 <= z-1) ripe(x, y, z-1, t);
		if(z+1 < h) ripe(x, y, z+1, t);

		q_cursor ++;
	}

	for(int k = 0; k < h; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(box[i][j][k] == 0) result = -1; 

	printf("%d\n", result);

	return 0;
}
