#include <cstdio>
#include <algorithm>
#include <queue>

using std::priority_queue;

constexpr int N = 1005;
constexpr int NONE = -1;

struct Compare{
	bool operator()(
		const std::pair<int, int>& x, 
		const std::pair<int, int>& y
	){
		return x.second > y.second;
	}
};


void dijkstra(int src, int arr[][N], int* dist, int n){
	priority_queue<
		std::pair<int, int>,
		std::vector<std::pair<int, int>>,
		Compare
	> q{};
	q.push({src, 0});

	while(!q.empty()){
		auto [cur, cost] = q.top(); q.pop();
		if(dist[cur] != NONE && dist[cur] < cost) continue;

		for(int dest = 1; dest <= n; dest ++){
			if(arr[cur][dest] == NONE) continue;
			
			if(
				dist[dest] == NONE || 
				cost + arr[cur][dest] < dist[dest]
			){
				dist[dest] = cost + arr[cur][dest];
				q.push({dest, dist[dest]});
			}
		}
	}
}

int main(){
	int arr[N][N] = { 0, };	
	int dist[N][N] = { 0, };

	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			arr[i][j] = NONE;
			dist[i][j] = NONE;
		}
		dist[i][i] = 0;
	}
	
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < m; i ++){
		int s, d, c;
		scanf("%d %d %d", &s, &d, &c);
		arr[s][d] = c;
	}
	for(int i = 1; i <= n; i ++)
		dijkstra(i, arr, dist[i], n);
	int result = 0;
	for(int i = 1; i <= n; i ++){
		if(i == x) continue;
		result = std::max(result, dist[i][x] + dist[x][i]);
	}
	printf("%d\n", result);


	return 0;
}
