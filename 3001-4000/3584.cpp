#include <cstdio>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

constexpr int N = 10001;
constexpr int LN = 14;

template <typename T>
void build_depth(T& graph, int* depth, int idx){
	for(int x: graph[idx]){
		depth[x] = depth[idx] + 1;
		build_depth(graph, depth, x);
	}
	return;
}
int main(){
	int t = 0;
	scanf("%d", &t);

	while(t--){
		unordered_map<int, vector<int>> graph{};
		int depth[N] = { 0, };
		int table[LN][N] = { 0, };	

		int n, root = -1;
		scanf("%d", &n);
		for(int i = 0; i < n-1; i ++){
			int parent, child;
			scanf("%d %d", &parent, &child);
			graph[parent].push_back(child);
			table[0][child] = parent;

			if(root == -1 || root == child) root = parent;
		}
		build_depth(graph, depth, root);

		for(int i = 1; i < LN; i ++)
			for(int x = 1; x <= n; x ++)
				if(table[i-1][x] != 0) 
					table[i][x] = table[i-1][table[i-1][x]];

		int u, v;
		scanf("%d %d", &u, &v);
		
		if(depth[u] > depth[v]){
			int tmp = u; u = v; v = tmp;
		}
		
		int diff = depth[v] - depth[u];
		for(int idx =LN-1; idx >= 0; idx --){
			if((diff & (1 << idx)) == (1 << idx)){
				v = table[idx][v];
			}
		}

		if(u != v){
			for(int idx = LN-1; idx >= 0; idx --){
				if(table[idx][u] != 0 && table[idx][u] != table[idx][v]){
					u = table[idx][u];
					v = table[idx][v];
				}
			}
			u = table[0][u];
		}

		printf("%d\n", u);

	}
	return 0;
}
