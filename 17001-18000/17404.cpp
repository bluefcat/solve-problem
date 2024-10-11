#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

using pair = std::pair<int, int>;
using queue = std::queue<pair>;

constexpr int N = 1002;
int field[N][3];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		for(int c = 0; c < 3; c ++)
			scanf("%d", field[i]+c);

	int backup[3] = {field[0][0], field[0][1], field[0][2]};
	int tmp[3][2] = { 0, };

	for(int i = 0; i < 3; i ++){
		int cache[N][3] = { 0, };
		for(int j = 0; j < 3; j ++){
			field[0][j] = INT_MAX >> 1;
			if(i == j) field[0][j] = backup[i];
			cache[0][j] = field[0][j];
		}

		
		for(int x = 1; x < n; x ++){
			for(int c = 0; c < 3; c ++){
				cache[x][c] = cache[x-1][(c+1)%3] + field[x][c];
				for(int d = 0; d < 3; d ++){
					if(c == d) continue;
					cache[x][c] = std::min(cache[x][c], cache[x-1][d] + field[x][c]);
				}
			}
		}

		for(int j = 0, cnt = 0; j < 3; j ++){
			if(i == j) continue;
			tmp[i][cnt++] = cache[n-1][j];	
		}
	}

	
	int result = tmp[0][0];
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 2; j ++)
			result = std::min(result, tmp[i][j]);

	printf("%d\n", result);
	
	return 0;
}

