#include <cstdio>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

constexpr int N = 255;

int main(){
	unordered_map<
		char, unordered_map<char, int>
	> capacity{}, flow{};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		char u, v;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		capacity[u][v] += w;
		capacity[v][u] += w;
		flow[u][v] = 0;
	}

	int result = 0;
	char s = 'A', e = 'Z';

	while(1){
		char table[N] = { 0, };
		queue<char> q{};
		q.push(s);
		while(!q.empty() && !table[e]){
			char cur = q.front(); q.pop();
			for(auto& [next, w]: capacity[cur]){
				//not enoght or already visited
				if(w <= flow[cur][next]) continue;
				if(table[next]) continue;

				q.push(next);
				table[next] = cur;

				if(next == e) break;
			}
		}
		//if not reached dest
		if(!table[e]) break;

		int f = capacity[table[e]][e] - flow[table[e]][e];
		for(int i = table[e]; i != s; i = table[i])
			f = std::min(
				f, capacity[table[i]][i] - flow[table[i]][i]
			);
		
		for(int i = e; i != s; i = table[i]){
			flow[table[i]][i] += f;
			flow[i][table[i]] += f;
		}	
		result += f;
	}
	printf("%d\n", result);

	return 0;
}
