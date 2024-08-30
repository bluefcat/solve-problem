#include <cstdio>
#include <climits>
#include <algorithm>

using std::max;

constexpr int N = 1001;
constexpr int l = 0;
constexpr int r = 1;
int field[N][N] = { 0, };
int cache[N][N][2] = { 0, };

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++){
			scanf("%d", field[i]+j);
			cache[i][j][l] = INT_MIN;
			cache[i][j][r] = INT_MIN;
		}
	
	cache[0][0][r] = field[0][0];
	for(int i = 1; i < m; i ++){
		cache[0][i][r] = cache[0][i-1][r] + field[0][i];
	}

	for(int i = 1; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cache[i][j][r] = max(cache[i-1][j][l], cache[i-1][j][r]) + field[i][j];
			cache[i][j][l] = max(cache[i-1][j][l], cache[i-1][j][r]) + field[i][j];
		}
		for(int j = 1; j < m; j ++)
			cache[i][j][r] = max(cache[i][j][r], cache[i][j-1][r] + field[i][j]);
		for(int j = m-2; j >= 0; j --)
			cache[i][j][l] = max(cache[i][j][l], cache[i][j+1][l] + field[i][j]);
	}

	printf("%d\n", max(cache[n-1][m-1][l], cache[n-1][m-1][r]));
	return 0;
}
