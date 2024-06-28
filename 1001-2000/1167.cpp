#include <cstdio>
#include <unordered_map>
#include <queue>
#include <algorithm>

template<typename T>
std::pair<int, long long> get_start(
	T& tree,
	std::unordered_map<int, bool>& check,
	int x
){
	std::pair<int, long long> result{x, 0};
	check[x] = true;
	for(const auto& [y, cost]: tree[x]){
		if(check[y]) continue;
		auto p = get_start(tree, check, y);
		if(result.second < p.second + cost){
			result = std::make_pair(p.first, p.second + cost);
		}
	}
	return result;
}

template<typename T>
long long visit(
	T& tree,
	std::unordered_map<int, bool>& check,
	int x
){
	long long result = 0;
	check[x] = true;
	for(const auto& [y, cost]: tree[x]){
		if(check[y]) continue;
		result = std::max(result, visit(tree, check, y) + cost);
	}
	return result;
}


int main(){
	std::unordered_map<
		int,
		std::unordered_map<int, int>
	> tree;
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int x, y, t, flag = 0;
		scanf("%d", &x);
		while(scanf("%d", &t) && t != -1){
			if(flag == 0)
				y = t;
			else
				tree[x][y] = t;
			flag = (flag + 1) %2;
		}	
	}
	std::queue<int> q;
	
	long long result = 0;
	std::unordered_map<int, bool> check;
	auto idx = get_start(tree, check, tree.begin()->first);
	check.clear();
	result = visit(tree, check, idx.first);
	printf("%lld\n", result);

	return 0;
}
