#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <queue>

using std::pair;
using std::tuple;
using std::vector;
using std::unordered_map;
using std::priority_queue;


constexpr int N = 1000;
constexpr int L = 1000000;

template<>
struct std::hash<pair<int, int>>{
	std::size_t operator()(
		const pair<int, int>& x
	) const {
		return std::hash<int>()(
			(x.first << 10) + x.second
		);
	}
};

struct TupleGreater{
	bool operator()(
		tuple<int, int, double>& x,
		tuple<int, int, double>& y
	){
		return std::greater<double>()(
			std::get<2>(x), std::get<2>(y)
		);
	}
};

double get_distance(
	const pair<int, int>& x,
	const pair<int, int>& y
){
	return std::sqrt(
		std::pow(x.first-y.first, 2) + 
		std::pow(x.second-y.second, 2)
	);
}

template<typename T>
auto find(T& parent, int& pos){
	if(parent[pos] == pos) return pos;
	return parent[pos] = find(parent, parent[pos]); 
}

template<typename T>
bool combine(
	T& parent,
	int x,
	int y
){
	auto px = find(parent, x);
	auto py = find(parent, y);

	if(px == py) return false;

	auto t = std::min(px, py);
	
	parent[x] = t;
	parent[y] = t;
	
	return true;
}

int main(){
	int n, m;
	vector<pair<int, int>> p{};
	unordered_map<int, int> parent{};

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		p.push_back({x, y});
		parent[i] = i;
	}
	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		combine(parent, x-1, y-1);
	}

	priority_queue<
		tuple<int, int, double>,
		vector<tuple<int, int, double>>,
		TupleGreater
	> q{};

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j) continue;
			q.push({i, j, get_distance(p[i], p[j])});
		}
	}

	double result = 0.0;
	while(!q.empty()){
		auto& [x, y, d] = q.top();
		if(!combine(parent, x, y)){
			q.pop(); 
			continue;
		}
		result += d;
		q.pop();
	}
	printf("%.2lf\n", result);

	return 0;
};
