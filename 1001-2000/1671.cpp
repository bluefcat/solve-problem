#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

constexpr int N = (50<<1) + 1;

bool is_strong(int x[3], int y[3]){
	bool result = true;
	for(int i = 0; i < 3; i ++)
		result &= (x[i] >= y[i]);
	return result;
}

template<typename U>
bool find(U& b, int cur, int target){
	while(cur != -1){
		cur = b[cur] - (b[cur]%2==0);
		if(target == cur || target+1 == cur) return true;
	}
	return false;
}

template<typename T, typename U, typename V>
bool predict(T& graph, U& a, U& b, int cur, V& check){
	int idx = cur - (cur%2==0);
	check[cur] = true;

	for(int next: graph[idx]){
		if(find(b, idx, next)) continue;
		if(
			!b[next] || 
			!check[b[next]] && predict(graph, a, b, b[next], check)
		){
			a[cur] = next;
			b[next] = cur;
			return true;
		}
	}

	return false;
}


int main(){
	unordered_map<int, unordered_set<int>> graph{};
	int a[N] = { 0, };
	int b[N] = { 0, };
	int shark[N][3] = { 0, };

	int n;
	scanf("%d", &n);
	for(int i = 1; i < 2*n+1; i +=2)
		scanf("%d %d %d", shark[i]+0, shark[i]+1, shark[i]+2);
	
	
	for(int i = 1; i < 2*n+1; i += 2){
		for(int j = i+2; j < 2*n+1; j += 2){
			if(is_strong(shark[i], shark[j])){ 
				graph[i+0].insert(j);
				graph[i+1].insert(j);
			}
			//case shark[i]'s prop equal shark[j]'s prop	
			if(is_strong(shark[j], shark[i])){
				graph[j+0].insert(i);
				graph[j+1].insert(i);
			}
		}
	}

	
	int eat = 0;
	for(int i = 1; i < 2*n+1; i ++){
		int check[N] = { false, };
		eat += predict(graph, a, b, i, check);
	}

	printf("%d\n", n-eat);

	return 0;
}
