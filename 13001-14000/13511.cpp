#include <cstdio>
#include <unordered_map>

using ll = long long;
using std::unordered_map;

constexpr int N = 10001; //100001;
constexpr int LN = 19;

template<typename T>
void build_depth(T& graph, int* depth, int table[][N], ll dist[][N], int root, int idx){
	for(auto [x, w]: graph[idx]){
		if(x == root || depth[x] != 0) continue;
		depth[x] = depth[idx]+1;
		table[0][x] = idx;
		dist[0][x] = w;
		build_depth(graph, depth, table, dist, root, x);
	}
	return ;
}

template<typename T>
std::tuple<ll, int, int> LCA(T& graph, int* depth, int table[][N], ll dist[][N], int u, int v){
	if(depth[u] > depth[v]){
		int tmp = u; u = v; v = tmp;
	}	
	ll d = 0;
	int cu = 0;
	int cv = 0;
	int diff = depth[v] - depth[u];
	for(int i = LN -1; i >= 0; i --){
		if((diff & (1 << i)) == (1 << i)){
			cv += 1 << i;
			d += dist[i][v];
			v = table[i][v];
		} 
	}
	if(u == v) cv --;
	if(u != v){
		for(int i = LN-1; i >= 0; i --){
			if(table[i][u] == 0 || table[i][u] == table[i][v]) continue;
			cu += (1 << i);
			cv += (1 << i);
			d += dist[i][u] + dist[i][v];
			u = table[i][u];
			v = table[i][v];
		}
		cu += 1;
		d += dist[0][u] + dist[0][v];
		u = table[0][u];
	}
	cu ++; cv ++; //include u, v
	return {d, cu, cv};
}

int main(){
	int depth[N] = { 0, };
	int table[LN][N] = { 0, };
	ll dist[LN][N] = { 0, };
	int n;
	unordered_map<int, unordered_map<int, int>> graph{};

	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u][v] = w;
		graph[v][u] = w;
	}

	build_depth(graph, depth, table, dist, 1, 1);
	for(int i = 1; i < LN; i ++){
		for(int x = 1; x <= n; x ++){
			if(table[i-1][x] != 0){
				table[i][x] = table[i-1][table[i-1][x]];
				dist[i][x] = dist[i-1][table[i-1][x]] + dist[i-1][x];
			}
		}
	}
	
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper, u, v, k = 0;
		scanf("%d %d %d", &oper, &u, &v);
		if(oper == 2) scanf("%d", &k);

		auto [d, cu, cv] = LCA(graph, depth, table, dist, u, v);	
		if(oper == 1){
			printf("%lld\n", d);
			continue;
		}
		if(depth[u] > depth[v]){
			int tmp = cu; cu = cv; cv = tmp;
		}
		int start = u;
		if(cu < k){
			start = v;
			k = cv - (k-cu-1);
		}
		k --;
		for(int i = LN-1; i >= 0; i --){
			if((k & (1 << i)) == (1 << i)){
				start = table[i][start];
			}
		}
		printf("%d\n", start);

	}

	return 0;
}
