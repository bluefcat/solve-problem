#include <cstdio>
#include <algorithm>

using lint = long long;
using std::min;
constexpr int N = 16;

lint field[N][N] = { 0, };
lint cache[N][1<<N];

lint dfs(int n, int cur, int visit){
	if(visit == (1<<n)-1){
		if(field[cur][0] == 0) return -1;
		return field[cur][0];
	}

	if(cache[cur][visit]) return cache[cur][visit];

	for(int i = 0; i < n; i ++){
		if(field[cur][i] == 0 || (visit & (1 << i))) continue;

		lint r = dfs(n, i, visit | (1 << i));
		if(r == -1 || r == 0) continue;
		if(cache[cur][visit] == 0) 
			cache[cur][visit] = field[cur][i] + r;

		cache[cur][visit] = min(
			cache[cur][visit],
			field[cur][i] + r
		);
	}
	return cache[cur][visit];
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%lld", field[i]+j);
		}
	}

	printf("%lld\n", dfs(n, 0, 1));

	return 0;
}
