#include <stdio.h>

int n, m;
int map[51][51];

//cleaner
int r, c, d;
int stop;

//north, east, south, west
int dx[] = {  0, -1,  0,  1};
int dy[] = { -1,  0,  1,  0};

int rotate[] = {3, 0, 1, 2};

int main(){
	int result = 0;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n ; j ++) scanf("%d", map[i]+j);
	}

	//implement
	while(!stop){
		//step 1
	ONE:
		if(map[r][c] == 0){
			map[r][c] = -1;
			result ++;
		}
	
		//step 2
	int checker = 0;
	TWO:
	{
		int lx = dx[d];
		int ly = dy[d];

		if(map[r+lx][c+ly] == 0){
			d = rotate[d];
			r += lx;
			c += ly;
			//goto step 1
		}
		else{
			d = rotate[d];
			checker ++;
			if(checker != 4) goto TWO;
		}

		if(checker == 4){
			int nx = r - 2*lx;
			int ny = c - 2*ly;

			if(map[r-lx][c-ly] == 1){
				break;
			}

			r = nx, c = ny;
			goto TWO;
		}

	}	
	}
	
	printf("%d\n", result);

	return 0;
}
