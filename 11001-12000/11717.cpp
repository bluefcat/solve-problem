#include <cstdio>
#include <array>

using std::array;

constexpr int N = 21;
int cache[N][N][N][N] = { 0, };

inline bool isin(int l, int a0, int a1){
	return (0 <= a0 && a1 <= l) && (a0 <= a1);
}

template<typename T>
int grundy(T& board, int w, int h, int x0, int x1, int y0, int y1){
	if(!(isin(w, x0, x1) && isin(h, y0, y1))) return 0;
	if(cache[x0][x1][y0][y1] != -1) return cache[x0][x1][y0][y1];
	if(x0 == x1 && y0 == y1){
		return board[y0][x0] == '.';
	}
	
	bool check[N*N] = { false, };

	for(int y = y0; y <= y1; y ++){
		for(int x = x0; x <= x1; x ++){
			if(board[y][x] != '.') continue;
			int result = 0;
			result ^= grundy(board, w, h, x0, x-1, y0, y-1); 
			result ^= grundy(board, w, h, x0, x-1, y+1, y1);
			result ^= grundy(board, w, h, x+1, x1, y0, y-1);
			result ^= grundy(board, w, h, x+1, x1, y+1, y1);
			check[result] = true;
		}
	}
	
	int r = 0;
	for(int i = 0; i < N*N; i ++){
		if(!check[i]){
			r = i; break;
		}
	}
	return cache[x0][x1][y0][y1] = r;
}

int main(){
	for(int x0 = 0; x0 < N; x0 ++)
		for(int x1 = 0; x1 < N; x1 ++)
			for(int y0 = 0; y0 < N; y0 ++)
				for(int y1 = 0; y1 < N; y1 ++)
					cache[x0][x1][y0][y1] = -1;
	
	int h, w;
	array<array<char, N>, N> board{};
	scanf("%d %d", &h, &w);
	
	for(int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
			char tmp;
			scanf(" %c", &tmp);
			board[i][j] = tmp;
		}
	}

	int result = grundy(board, w-1, h-1, 0, w-1, 0, h-1);

	if(result) printf("First\n");
	else printf("Second\n");

	return 0;
}
