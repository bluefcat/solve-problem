#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>

using std::vector;
using std::queue;
using std::unordered_map;

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n, m;
		vector<int> result{};

		unordered_map<
			int, 
			unordered_map<int, int>
		> graph{};
		vector<int> order{};
		scanf("%d", &n);

		for(int i = 0; i <= n; i ++)
			order.push_back(0);

		for(int i = 0; i < n; i ++){
			int x;
			scanf("%d", &x);
			order[x] = i;
			for(const auto& [y, _]: graph)
				graph[y][x] = 1;
			graph[x][x] = 0;
		}


		scanf("%d", &m);
		for(int i = 0; i < m; i ++){
			int x, y;
			scanf("%d %d", &x, &y);
			
			int src = x;
			int dest = y;
			if(graph[x][y] == 0){
				src = y;
				dest = x;
			}	
			order[src] ++;
			order[dest] --;
			graph[src][dest] = 0;
			graph[dest][src] = 1;
		}

		queue<int> q{};

		for(int i = 1; i <= n; i++){
			if(order[i] == 0) q.push(i);
		}

		for(int i = 0; i < n; i ++){
			if(q.empty()){
				printf("IMPOSSIBLE\n");
				goto END;
			}
			int cur = q.front(); q.pop();
			result.push_back(cur);
			for(const auto& [y, _]: graph[cur]){
				if(--order[y] == 0) q.push(y);
			}

		}

		for(auto x: result)
			printf("%d ", x);
		printf("\n");
		END:
			continue;
		
	}

	return 0;
}
