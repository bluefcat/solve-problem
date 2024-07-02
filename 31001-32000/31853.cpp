#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <limits.h>

struct Compare{
	bool operator()(
		std::pair<int, int> x, 
		std::pair<int, int> y){
		return x.first > y.first;
	}
};

static inline int get_left(int x){ return (x << 1) + 1; }
static inline int get_right(int x){ return (x << 1) + 2; }

template<typename T>
long long init(
	T& tree,	
	int sidx, int eidx,
	int idx
){
	if(sidx == eidx){
		return tree[idx] = 1;
	}
	int midx = (sidx + eidx) >> 1;
	auto l = init(tree, sidx, midx, get_left(idx));
	auto r = init(tree, midx+1, eidx, get_right(idx));
	return tree[idx] = l+r;
}

template<typename D, typename T>
std::pair<int, int> get_range(
	const D& line,	
	T& tree,
	int sidx, int eidx,
	int x1, int x2,
	int idx
){
	if(x2 < line[sidx].first || line[eidx].first < x1) return {INT_MAX, -1};
	if(x1 <= line[sidx].first && line[eidx].first <= x2) return {sidx, eidx};

	int midx = (sidx + eidx) >> 1;
	auto l = get_range(line, tree, sidx, midx, x1, x2, get_left(idx));
	auto r = get_range(line, tree, midx+1, eidx, x1, x2, get_right(idx));
	return {std::min(l.first, r.first), std::max(l.second, r.second)};
}

template<typename D, typename T>
long long sum(
	const D& line,	
	T& tree,
	int sidx, int eidx,
	int le, int ri,
	int y,
	int idx
){
	if(ri < sidx || eidx < le) return 0;
	if(sidx == eidx) return (long long)(y <= line[sidx].second);
	if(y <= line[sidx].second && y <= line[eidx].second) return tree[idx];

	int midx = (sidx + eidx) >> 1;
	auto l = sum(line, tree, sidx, midx, le, ri, y, get_left(idx));
	auto r = sum(line, tree, midx+1, eidx, le, ri, y, get_right(idx));
	return l+r;
}


int main(){
	int n, m;
	std::vector<std::pair<int, int>> line;
	std::unordered_map<int, long long> tree;

	long long result = 0;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		line.push_back(
			{std::min(x, y), std::max(x, y)}
		);
	}
	
	std::sort(
		line.begin(), 
		line.end(), [](const auto& x, const auto& y){
			return x.first < y.first;
	});
	
	init(tree, 0, line.size()-1, 0);
	for(const auto& [x1, y1]: line){
		for(const auto& [x2, y2]: line){
			if(!(x1 < x2 && x2 < y1 && y1 < y2)) continue;
			//y2 < y3
			auto r = get_range(line, tree, 0, line.size()-1, x2+1, y1-1, 0);
			if(r.second == -1) continue;
			result += sum(line, tree, 0, line.size()-1,r.first, r.second, y2+1, 0);
		}
	}

	printf("%lld\n", result);
	return 0;
}
