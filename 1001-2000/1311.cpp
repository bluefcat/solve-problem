#include <cstdio>
#include <algorithm>
#include <utility>

using std::min;
using pair = std::pair<int, int>;

constexpr int N = 21;
pair cache[N][N];

int main(){
	int field[N][N] = { 0, };
	int n = 20;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n; j ++)
			scanf("%d", field[i]+j);
	}
	
	//employee
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n; j ++){
			auto [prev, flag] = cache[i-1][j];
			//task
			for(int t = 0; t < n; t ++){
				auto [cur, _] = cache[i][j];
				if((flag & (1 << t)) == (1 << t)) continue;
				if(cur != 0 && cur < prev + field[i][t])
					continue;
				cache[i][j] = {prev + field[i][t], flag ^ (1 << t)};
			}
		}
	}
	
	int result = 0;
	for(int i = 0; i < n; i ++){
		if(result != 0 && result < cache[n][i].first) continue;
		result = cache[n][i].first;
	}

	printf("%d\n", result);


	return 0;
}
