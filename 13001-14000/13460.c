#include <stdio.h>

#define QSIZE 10485771
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define ABS(X) (((X) > 0)? (X): -(X))

#define PUSH(COLOR, X, Y, C) \
	COLOR##_queue[COLOR##_tail][0] = X; \
	COLOR##_queue[COLOR##_tail][1] = Y; \
	COLOR##_queue[COLOR##_tail][2] = C; \
	COLOR##_tail = (COLOR##_tail + 1) % QSIZE 	

#define POP(COLOR, X, Y, C) \
	int X = COLOR##_queue[COLOR##_head][0]; \
	int Y = COLOR##_queue[COLOR##_head][1]; \
	int C = COLOR##_queue[COLOR##_head][2]; \
	COLOR##_head = (COLOR##_head + 1) % QSIZE; 

//x, y, count
int red_queue[QSIZE][3];
int red_head, red_tail;

int blue_queue[QSIZE][3];
int blue_head, blue_tail;

int result = 99;

char map[11][11];
long long cnt[11];
long long check[11111111];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	//MAP INPUT
	for(int i = 0; i < n; i++){
		scanf(" ");
		for(int j = 0; j < m; j ++){
			scanf("%c", map[i]+j);
			
			if(map[i][j] == 'R'){
				PUSH(red, i, j, 0);
				map[i][j] = '.';
			}
			if(map[i][j] == 'B'){
				PUSH(blue, i, j, 0);
				map[i][j] = '.';
			}

		}
	}

	while(red_head != red_tail){
		POP(red, rx, ry, rc);
		POP(blue, bx, by, bc);
		check[rx + ry *100 + bx *10000 + by*1000000] = 1;
		for(int i = 0; i < 4; i ++){
			int rflag = 0; int bflag = 0;
			int rnx = rx; int rny = ry;
			int bnx = bx; int bny = by;
			while(map[rnx][rny] == '.'){
				rnx += dx[i]; rny += dy[i];
				if(map[rnx][rny] == 'O') rflag = 1;
			}
			rnx -= dx[i]; rny -= dy[i];

			while(map[bnx][bny] == '.'){
				bnx += dx[i]; bny += dy[i];
				if(map[bnx][bny] == 'O') bflag = 1;
			}
			bnx -= dx[i]; bny -= dy[i];
			
			if(rnx == bnx && rny == bny){
				int fx = dx[i] * ((rx-bx)/ABS(rx-bx));
				int fy = dy[i] * ((ry-by)/ABS(ry-by));
				

				if(fx < 0 || fy < 0){
					rnx -= dx[i]; rny -= dy[i];
					if(bflag) rflag = 0;
				}
				else{
					bnx -= dx[i]; bny -= dy[i];
					if(bflag) rflag = 0;
				}

			}
			if(rflag){
				result = MIN(result, rc);
			}
			
			int key = rnx + rny * 100 + bnx * 10000 + bny * 1000000;

			if(rc < 10 && 
			   !bflag  &&
			   (!(rnx == rx && rny == ry) || 
			   !(bnx == bx && bny == by)) &&
			   !check[key]
			   ){
				cnt[rc] = cnt[rc] * 10 + (i+1);		
				check[key] = 1;
				PUSH(red, rnx, rny, rc+1);
				PUSH(blue, bnx, bny, bc);	
			}

		}
	}
	result += 1;
	if(result >= 11) result = -1;
	printf("%d\n", result);
	return 0;
}
