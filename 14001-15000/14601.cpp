#include <cstdio>

constexpr int N = 1 << 7;

int field[N][N];
int idx = 0;

int block[2][2] = {
	{1, 0}, 
	{1, 1}
};

void rotate(int target[][2]){
	int result[2][2] = {};
	for(int i = 0; i < 4; i ++)
		result[i/2][!(i%2)] = target[i%2][i/2];
	
	for(int i = 0; i < 4; i ++) 
		target[i/2][i%2] = result[i/2][i%2];
}

void set_block(int size, int e, int x, int y){
	// e = {0, 1, 2, 3} ~ {north, east, souht, west}
	e %= 4;
	if(size == 2){
		idx ++;
		int _block[2][2] = {};
		for(int i = 0; i < 4; i ++) _block[i/2][i%2] = block[i/2][i%2];
		for(int i = 0; i < e; i ++) rotate(_block);
		for(int i = 0; i < 4; i ++) if(_block[i/2][i%2]) field[y+(i/2)][x+(i%2)] = idx;
		return;
	}

	int rot[3] = {e+1, e, e+3};
	int offset[4][2] = {{0, 0}, {0, size>>1}, {size>>1, size>>1}, {size>>1, 0}};

	set_block(size>>1, e, x+(size>>2), y+(size>>2));
	for(int i = 0; i < 3; i ++){
		int p = (i-e) % 4;
		p += (p < 0)?4:0;
		set_block(size>>1, rot[i], x+offset[p][0], y+offset[p][1]);
	}


	return;
}

void solve(int size, int px, int py, int x, int y){
	if(size==1)return;
	if(px >= (size >>1) && py  >= (size >> 1)){
		set_block(size, 1, x, y);
		solve(size >> 1, px-(size>>1), py-(size>>1), x +(size >> 1), y+(size>>1));
		return;
	}
	if(px >= (size >> 1)){
		set_block(size, 0, x, y);
		solve(size >> 1, px-(size>>1), py, x+(size>>1), y);
		return;
	}
	if(py >= (size >> 1)){
		set_block(size, 2, x, y);
		solve(size >> 1, px, py -(size>>1), x, y+(size>>1));
		return;
	}
	set_block(size, 3, x, y);
	solve(size >> 1, px, py, x, y);
}

int main(){
	int k, x, y;
	scanf("%d %d %d", &k, &x, &y);

	x--; y--;

	field[y][x] = -1;

	solve(1<<k, x, y, 0, 0);
	for(int i = (1 << k) - 1; i >= 0; i --){ // y
		for(int j = 0; j < (1 << k); j ++){
			field[y][x] = -1;
			printf("%d ", field[i][j]);
		}
		printf("\n");

	}

	

	return 0;
}
