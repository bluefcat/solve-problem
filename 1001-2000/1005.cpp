#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>

using std::queue;
using std::vector;
using std::unordered_map;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		unordered_map <
			int,
			vector<int>
		> graph{};
		vector<int> order(n+1, 0);
		vector<int> time(n+1, 0);
		vector<int> cache(n+1, 0);
		
		for(int i = 1; i <= n; i ++){
			int t;
			scanf("%d", &t);
			time[i] = t;
		}

		for(int i = 0; i < m; i ++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			order[y] ++;
		}

		int result = 0;
		scanf("%d", &result);
		
		queue<int> q{};
		
		for(int i = 1; i <= n; i ++){
			if(order[i] == 0) q.push(i);
		}

		for(int i = 0; i < n; i ++){
			if(q.empty()) break;

			int cur = q.front(); q.pop();
			for(auto x: graph[cur]){
				if(--order[x] == 0) q.push(x);
				cache[x] = std::max(
					cache[x], 
					cache[cur] + time[cur]
				);
			}
		}

		printf("%d\n", cache[result] + time[result]);
	}
	return 0;
}
