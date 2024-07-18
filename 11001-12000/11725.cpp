#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>

using std::vector;
using std::queue;
using std::unordered_map;

int main(){
	int n = 0;
	vector<int> parent{};
	unordered_map<
		int,
		vector<int>
	> graph{};

	scanf("%d", &n);
	for(int i = 0; i <= n; i ++)
		parent.push_back(0);

	for(int i = 0; i < n-1; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	queue<int> q{{1}};
	vector<bool> check{};
	for(int i = 0; i <= n; i ++)
		check.push_back(false);
	check[1] = true;

	while(!q.empty()){
		int p = q.front(); q.pop();
		
		for(int x: graph[p]){
			if(check[x]) continue;
			parent[x] = p;
			q.push(x);
			check[x] = true;
		}
	}


	for(int i = 2; i <= n; i ++)
		printf("%d\n", parent[i]);
	return 0;
}
