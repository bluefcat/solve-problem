#include <cstdio>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

constexpr int N = 501;

int main(){
	unordered_map<
		int, unordered_map<int, int>
	> graph{}, flow{};
	int n, p;
	scanf("%d %d", &n, &p);

	for(int i = 0; i < p; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 0;
		flow[u][v] = 0;
		flow[v][u] = 0;
	}

	int result = 0, s = 1, e = 2;
	while(true){
		int table[N] = { 0, };
		queue<int> q{};
		table[s] = s;
		q.push(s);

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

