#include <stdio.h>
#define MQ 1000000

typedef struct _pos{
	int x;
	int y;
} pos;

int field[1000][1000];
int visited[1000][1000];

int s, e;
pos queue[MQ];

int main(){
	int m = 0, n = 0;
	scnaf("%d %d", &m, &n);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			scanf("%d", field[i][j]);
			if(field[i][j] == 1){
				queue[e].x = i; queue[e].y = j;
				e ++
			}
		}
	}
	
	while(s != e){
		int x = queue[s].x; int y = queue[s].y;
		s = (s+1) % MQ;
		
		

	}

	return 0;
}
