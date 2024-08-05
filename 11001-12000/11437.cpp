#include <cstdio>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

constexpr int N = 50001;
constexpr int LN = 19;

template<typename T>
void build_depth(
	T& graph, int* depth, int table[][N], int root, int idx	
){
	for(auto n: graph[idx]){
		if(root == n || depth[n] != 0) continue;	
		table[0][n] = idx;
		depth[n] = depth[idx]+1;
		build_depth(graph, depth, table, root, n);
	}
}

int LCA(int* depth, int table[][N], int u, int v){
	if(depth[u] > depth[v]){
		int tmp = u; u = v; v = tmp;
	}
	
	int diff = depth[v] - depth[u];
	
	for(int i = LN-1; i >= 0; i --){
		if((diff & (1 << i)) == (1 << i)) v = table[i][v];
	}

	if(u != v){
		for(int i = LN-1; i >= 0; i --){
			if(table[i][u] != 0 && table[i][u] != table[i][v]){
				u = table[i][u];
				v = table[i][v];
			}
		}
		u = table[0][u];
	}
	return u;
}

int main(){
	unordered_map<int, vector<int>> graph{};
	int depth[N] = { 0, };
	int table[LN][N] = { 0, };
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	build_depth(graph, depth, table, 1, 1);

	for(int i = 1; i < LN; i ++){
		for(int x = 1; x <= n; x ++){
			if(table[i-1][x] != 0)
				table[i][x] = table[i-1][table[i-1][x]];
		}
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", LCA(depth, table, x, y));
	}

	return 0;
}
