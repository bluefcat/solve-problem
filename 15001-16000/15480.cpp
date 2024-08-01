#include <cstdio>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

constexpr int N = 100003;
constexpr int LN = 19;

template<typename T>
void build_depth(T& graph, int* depth, int table[][N], int root, int idx){
	for(auto x: graph[idx]){
		if(x == root || (x != root && depth[x] != 0)) continue;
		depth[x] = depth[idx]+1;
		table[0][x] = idx;
		build_depth(graph, depth, table, root, x);
	}
	return;
}

int main(){
	unordered_map<int, vector<int>> graph{};	
	int n = 0;

	scanf("%d", &n);

	for(int i = 0; i < n-1; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
    
	int m = 0;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
        
	    int depth[N] = { 0, };
	    int table[LN][N] = { 0, };
	    build_depth(graph, depth, table, t, t);
	
	    for(int i = 1; i < LN; i ++)
		    for(int x = 1; x <= n; x ++)
			    if(table[i-1][x] != 0)
				    table[i][x] = table[i-1][table[i-1][x]];	
		
		int du = depth[u];
		int dv = depth[v];
		
		if(du > dv){ 
			int tmp = du; du = dv; dv = tmp; 
			tmp = u; u = v; v = tmp;
		}
		
		int diff = dv - du;	
		for(int idx = LN-1; idx >= 0; idx --){
			if((diff & (1 << idx)) == (1 << idx)) {
				v = table[idx][v];
			}
		}
		
		if(u != v){
			for(int idx = LN-1; idx >= 0; idx--){
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
