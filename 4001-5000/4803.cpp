#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

using std::unordered_map;
using std::vector;
using std::queue;

constexpr int N = 502;

int find(int* parent, int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

bool combine(int* parent, int x, int y){
	int px = find(parent, x);
	int py = find(parent, y);
	if(px == py) return false;
	
	if(px < py){
		parent[py] = px;
		return true;
	}
	parent[px] = py;
	return true;
}

int main(){
	int n, m, cnt = 0;
	while(
		scanf("%d %d", &n, &m) && 
		(n != 0 && m != 0)
	){
		cnt ++;
		unordered_map<int, vector<int>> graph{};
		bool f[N] = { 0, };
		bool tree[N] = { 0, };
		int parent[N] = { 0, };
		for(int i = 1; i <= n; i ++){ 
			parent[i] = i;
			f[i] = true;
		}

		for(int i = 0; i < m; i ++){
			int u, v;
			bool pass = false;
			scanf("%d %d", &u, &v);

			for(auto& k: graph[u]){
				if(k == v) pass = true;
			}

			for(auto& k: graph[v]){
				if(k == u) pass = true;
			}
			if(pass) continue;

			graph[u].push_back(v);
			graph[v].push_back(u);
			f[u] = combine(parent, u, v);	
			f[v] = f[u];
		}

		bool check[N] = { false, };
		queue<int> q{};
		for(int i = 1; i <= n; i ++){
			if(f[i] || check[i]) continue;
			q.push(i);
			check[i] = true;
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(auto& v: graph[u]){
					if(check[v]) continue;
					q.push(v);
					check[v] = true;
					f[v] = 0;
				}
			}
		}

		int result = 0;
		for(int i = 1; i <= n; i ++){
			if(f[i] == 0) continue;
			if(tree[parent[i]]) continue;
			result ++;
			tree[parent[i]] = true;
		}
		printf("Case %d: ", cnt);
		if(result == 0){
			printf("No trees.\n");
		}
		else if(result == 1){
			printf("There is one tree.\n");
		}
		else{
			printf("A forest of %d trees.\n", result);
		}
	}
	return 0;
}
