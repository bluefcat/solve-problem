#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

constexpr int N = 501;

unordered_map<int, unordered_set<int>> graph{};
unordered_map<int, int> a{}, b{};

bool visited[N] = { 0, };

bool match(int n, int cur){
	visited[cur] = true;
	
	for(auto next: graph[cur]){
		if(b[next] == 0 || !visited[b[next]] && match(n, b[next])){
			a[cur] = next;
			b[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].insert(y);
	}

	for(int i = 1; i <= n; i ++){
		for(int x = 1; x <= n; x ++) visited[x] = false;
		match(n, i);	
	}
	
	int result = 0;
	for(int i = 1; i <= n; i ++){
		result += (a[i] != 0);
	}
	printf("%d\n", result);

	return 0;
}
