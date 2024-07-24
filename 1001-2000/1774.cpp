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

using ll=long long;

constexpr int N = 1000;
constexpr int L = 1000000;

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
	const pair<ll, ll>& x,
	const pair<ll, ll>& y
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
	
	if(px < py){
		parent[py] = px;
		return true;
	}
	parent[px] = py;
	return true;
}

int main(){
	int n, m;
	vector<pair<ll, ll>> p{};
	unordered_map<int, int> parent{};

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
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
			if(find(parent, i) == find(parent, j)) 
				continue;
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
		printf("(%d-%d) %lf %lf\n", x, y, d, result);
		q.pop();
	}
	printf("%.2lf\n", round(result*100)/100);
	return 0;
};
