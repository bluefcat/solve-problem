#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::vector;
using std::queue;

constexpr int N = 10001;
constexpr int M = 100001;

int main(){
	unordered_map<int, unordered_map<int, int>> graph{};
	unordered_map<int, vector<vector<int>>> paths{};
	int degree[N] = { 0, };
	//time
	int cache[N]{};

	int n, m, s, e;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		graph[u][v] = t;
		degree[v] ++;
	}
	scanf("%d %d", &s, &e);
	
	queue<int> q{};
	q.push(s);

	cache[s] = 0;
	paths[s].push_back({s});

	for(int i = 0; i < n; i ++){
		int cur = q.front(); q.pop();
		for(auto& [next, t]: graph[cur]){
			degree[next] --;
			
			if(cache[next] <= t+cache[cur]){
				cache[next] = t+cache[cur];
				for(auto p: paths[cur]){
					p.push_back(next);
					paths[next].push_back(p);
				}
			}

			if(degree[next] == 0)
				q.push(next);
		}
	}
	
	int count = 0;
	unordered_map<int, unordered_map<int, bool>> check{};

	for(auto& p: paths[e]){
		int u = s;
		int tmp = 0;
		for(auto v: p){
			if(u == v) continue;
			tmp += graph[u][v];	
			u = v;
		}
		if(cache[e] != tmp) continue;
		u = s;
		for(auto v: p){
			if(u == v || check[u][v]) continue;
			check[u][v] = true;
			count ++;
			u = v;
		}
	}

	printf("%d\n%d\n", cache[e], count);


	return 0;
}
