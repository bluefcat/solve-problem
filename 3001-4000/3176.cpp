#include <cstdio>
#include <unordered_map>
#include <climits>
#include <algorithm>

using ll = long long;
using std::unordered_map;

constexpr int N = 10001; //100001;
constexpr int LN = 19;

template<typename T>
void build_depth(T& graph, int* depth, int table[][N], ll dist[][N][2], int root, int idx){
	for(auto [x, w]: graph[idx]){
		if(x == root || depth[x] != 0) continue;
		depth[x] = depth[idx]+1;
		table[0][x] = idx;
		dist[0][x][0] = w;
		dist[0][x][1] = w;
		build_depth(graph, depth, table, dist, root, x);
	}
	return ;
}

template<typename T>
std::tuple<ll, ll> LCA(T& graph, int* depth, int table[][N], ll dist[][N][2], int u, int v){
	if(depth[u] > depth[v]){
		int tmp = u; u = v; v = tmp;
	}	
	ll mind = LONG_LONG_MAX;
	ll maxd = LONG_LONG_MIN;
	int diff = depth[v] - depth[u];
	for(int i = LN -1; i >= 0; i --){
		if((diff & (1 << i)) == (1 << i)){
			mind = std::min(mind, dist[i][v][0]);
			maxd = std::max(maxd, dist[i][v][1]);
			v = table[i][v];
		} 
	}
	if(u != v){
		for(int i = LN-1; i >= 0; i --){
			if(table[i][u] == 0 || table[i][u] == table[i][v]) continue;
			mind = std::min(mind, dist[i][v][0]);
			mind = std::min(mind, dist[i][u][0]);
			maxd = std::max(maxd, dist[i][v][1]);
			maxd = std::max(maxd, dist[i][u][1]);
			u = table[i][u];
			v = table[i][v];
		}
		mind = std::min(mind, dist[0][v][0]);
		mind = std::min(mind, dist[0][u][0]);
		maxd = std::max(maxd, dist[0][v][1]);
		maxd = std::max(maxd, dist[0][u][1]);
		u = table[0][u];
	}
	return {mind, maxd};
}

int main(){
	int depth[N] = { 0, };
	int table[LN][N] = { 0, };
	ll dist[LN][N][2] = { 0, };
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
				if(dist[i][x][0] == 0){
					dist[i][x][0] = dist[i-1][table[i-1][x]][0];
				}
				dist[i][x][0] = std::min(
					dist[i-1][table[i-1][x]][0],
					dist[i-1][x][0]
				);
				dist[i][x][1] = std::max(
					dist[i-1][table[i-1][x]][1],
					dist[i-1][x][1]
				);
			}
		}
	}
	
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int u, v = 0;
		scanf("%d %d", &u, &v);

		auto [mind, maxd] = LCA(graph, depth, table, dist, u, v);	
		printf("%lld %lld\n", mind, maxd);

	}

	return 0;
}
