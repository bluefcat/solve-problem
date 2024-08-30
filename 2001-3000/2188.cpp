#include <cstdio>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

constexpr int N = 210;
int main(){
	unordered_map<
		int, unordered_map<int, int>
	> graph{}, flow{};

	int n, m, s = 202, e = 502;
	scanf("%d %d", &n, &m);
	for(int u = 1; u <= n; u ++){
		graph[s][u] = 1;
		graph[u][s] = 0;
	}

	for(int u = 1+N; u <=m+N; u ++){
		graph[u][e] = 1;
		graph[e][u] = 0;
	}

	for(int u = 1; u <= n; u ++){
		int s;
		scanf("%d", &s);
		for(int j = 0; j < s; j ++){
			int v = 0;
			scanf("%d", &v);
			graph[u][v+N] = 1;
			graph[v+N][u] = 0;
		}
	}
	
	int result = 0;
	while(true){
		int table[505] = { 0, };
	queue<int> q{};
		q.push(s);
		table[s] = s;
		while(!q.empty() && !table[e]){
			int cur = q.front(); q.pop();
			for(auto& [next, w]: graph[cur]){
				if(w <= flow[cur][next]) continue;
				if(table[next]) continue;
				q.push(next);
				table[next] = cur;
				if(next == e) break;
			}
		}
		if(!table[e]) break;

		int f = graph[table[e]][e] - flow[table[e]][e];
		for(int i = table[e]; i != s; i = table[i])
			f = std::min(
				f, graph[table[i]][i] - flow[table[i]][i]
			);
		
		for(int i = e; i != s; i = table[i]){
			flow[table[i]][i] += f;
			flow[i][table[i]] -= f;
		}
		result += f;
	}

	printf("%d\n", result);
	return 0;
}
