#include <cstdio>
#include <algorithm>
#include <unordered_map>

using std::min;

constexpr int N = 20;
int cache[1 << N] = { 0, };

int main(){
	int field[N+1][N] = { 0, };
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%d", field[i]+j);
		}
	}
	
	for(int s = 0; s < (1 << n); s ++){
		int i = __builtin_popcount(s) + 1;
		for(int t = 0; t < n; t ++){
			int task = 1 << t;
			if((s & task) == task) continue;
			if(cache[s | task] != 0 && cache[s | task] < field[i][t] + cache[s])
				continue;
			cache[s | task] = field[i][t] + cache[s];
		}
	}

	int result = cache[(1 << n)-1];
	printf("%d\n", result);

	return 0;
}
