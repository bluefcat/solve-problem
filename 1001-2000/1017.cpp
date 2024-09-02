#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

constexpr int N = 1001;
bool prime[N << 2] = { false, };

void get_prime(){
	prime[2] = true;
	for(int i = 3; i < (N << 2); i += 2){
		prime[i] = true;
	}

	for(int i = 3; i < (N << 2); i += 2){
		if(!prime[i]) continue;
		for(int j = 2; i*j < (N << 2); j ++)
			prime[i*j] = false;
	}
}

template<typename T, typename U>
bool match(T& graph, int cur, U& check){
	check[cur] = true;
	for(auto [next, matched]: graph){
		if(cur == next || !prime[cur+next]) continue;
		if(matched == 0 || !check[matched] && match(graph, matched, check)){
			graph[cur] = next;
			graph[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	get_prime();
	int n = 0, f = 0;
	unordered_map<int, int> graph{};
	unordered_map<int, bool> check{};
	vector<int> result{};
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int x;
		x = i+1;
		scanf("%d", &x);
		if(f == 0) f = x;
		graph[x] = 0;
	}
	
	for(auto [a, _]: graph){
		if(a == f || !prime[a+f]) continue;
		for(auto [x, _]: graph) graph[x] = 0;
		graph[f] = a; graph[a] = f;
		for(auto [x, _]: graph){
			if(graph[x] == 0){
				for(auto [y, _]: check) check[y] = false;
				check[f] = true; check[a] = true;
				match(graph, x, check);
			}
		}

		bool flag = true;
		for(auto [x, matched]: graph)
			flag &= (matched!=0);
		

		if(!flag) continue;
		result.push_back(a);
	}
	if(result.size() == 0){
		printf("-1\n");
		return 0;
	}
	std::sort(result.begin(), result.end());
	for(int x: result){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}
