#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <queue>

constexpr int N = 16;
constexpr int M = 16;
constexpr int K = 101;

using map = std::unordered_map<int, int>;
using queue = std::queue<int>;
using std::min;

int main(){
	map info{};
	int cache[K] = { 0, };
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n+m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		info[u] = v;
	}
	
		queue q{};
		bool visit[K] = { false, };
		q.push(1);
		
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int d = 1; d <= 6; d ++){
			int next = min(100, cur + d);
			if(info[next] != 0) next = info[next];
			if(!visit[next]){
				visit[next] = true;
				if(cache[next] == 0) cache[next] = cache[cur]+1;
				cache[next] = min(cache[next], cache[cur]+1);
				q.push(next);
			}
		}

	}
	printf("%d\n", cache[100]);
	return 0;
}
