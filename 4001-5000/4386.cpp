#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <cmath>

using std::vector;
using std::array;
using std::priority_queue;
using std::tuple;
using std::pair;

constexpr int N = 101;

struct TupleCompare{
	bool operator()(
		const tuple<int, int, double>& x,
		const tuple<int, int, double>& y
	){
		return std::greater<double>()(
			std::get<2>(x), 
			std::get<2>(y)
		);
	}
};

double get_dist(
	const pair<double, double>& x,
	const pair<double, double>& y
){
	return std::sqrt(std::pow(x.first-y.first, 2) + std::pow(x.second-y.second,2));
}

template<typename T>
int find(T& parent, int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

template<typename T, typename U>
bool combine(T& parent, U& field, int x, int y){
	int px = find(parent, x);
	int py = find(parent, y);
	
	if(px == py) return false;
	
	parent[std::max(px, py)] = std::min(px, py);
	return true;
}


int main(){
	array<pair<double, double>, N> arr{};
	array<int, N> parent{};
	int n = 0;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i ++){
		scanf("%lf %lf", &arr[i].first, &arr[i].second);
		parent[i] = i;
	}
	priority_queue<
		tuple<int, int, double>,
		vector<tuple<int, int, double>>,
		TupleCompare
	> q{};
	
	for(int i = 0; i < n; i ++){
		for(int j = i+1; j < n; j ++){
			q.push({i, j, get_dist(arr[i], arr[j])});
		}
	}

	double result = 0.f;

	while(!q.empty()){
		auto [x, y, dist] = q.top(); q.pop();
		if(!combine(parent, arr, x, y)) continue;
		result += dist;
	}
	printf("%lf\n", result);

	return 0;
}
