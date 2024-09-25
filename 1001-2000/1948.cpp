#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

using std::unordered_map;
using std::vector;
using std::queue;

constexpr int N = 10001;
constexpr int M = 100001;

unordered_map<int, unordered_map<int, bool>> check{};
unordered_map<int, unordered_map<int, int>> graph{};

template<typename T>
bool find(T& rev, int cur, int c, int s, int k, int& result){
	if(cur == s){
		return c == k;
	}
	bool f = false;
	for(auto& next: rev[cur]){
		f |= find(rev, next, c+graph[next][cur], s, k, result);
		if(f){
			if(check[next][cur] != true) result ++;
			check[next][cur] = true;
		}
	}
	return f;
}

int main(){
	unordered_map<int, vector<int>> paths{};
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
				paths[next].push_back(cur);
			}

			if(degree[next] == 0)
				q.push(next);
		}
	}
	
	int count = 0;
	
	find(paths, e, 0, s, cache[e], count);

	printf("%d\n%d\n", cache[e], count);


	return 0;
}
