#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::pair;
using ll = long long;


constexpr int N = 200001;
constexpr int MOD = 1000000000+7;
constexpr int get_left(int x){
	return (x << 1) + 1;
}
constexpr int get_right(int x){
	return (x << 1) + 2;
}

template<>
struct std::hash<pair<int, int>>{
	auto operator()(const pair<int, int>& p) const{
		return std::hash<int>()(p.first * N + p.second);
	}
};

ll query(ll* tree, int l, int r, int s, int idx){
	if(r <= s) return 0;
	if(s < l) return tree[idx];
	int m = (l + r) >> 1;
	return query(tree, l, m, s, get_left(idx)) + 
		   query(tree, m+1, r, s, get_right(idx));
}

ll update(ll* tree, int l, int r, int k, int idx){
	if(!(l <= k && k <= r)) return tree[idx];
	if(l == r) return tree[idx] = tree[idx] + 1;

	int m = (l + r) >> 1;
	ll lr = update(tree, l, m, k, get_left(idx));
	ll rr = update(tree, m+1, r, k, get_right(idx));
	return tree[idx] = lr + rr;
}


int main(){
	ll lt[4*N+4] = { 0, };
	ll rt[4*N+4] = { 0, };


	vector<pair<int, int>> cord{};
	unordered_map<int, int> id{};
	unordered_map<pair<int, int>, ll> tmp{};
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		cord.push_back({x, y});
	}

	std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
		return p.second < q.second;
	});

	int cnt = 0;
	for(auto& [_, y]: cord)
		if(id[y] == 0)
			id[y] = ++cnt;	
	
	std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
		if(p.first == q.first) return p.second < q.second;
		return p.first < q.first;
	});

	for(const auto& p: cord){
		int y = p.second;
		ll r = query(lt, 1, cnt, id[y], 0);
		if(r != 0)
			tmp[p] = r;
		update(lt, 1, cnt, id[y], 0);
	}

	std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
		if(p.first == q.first) return p.second < q.second;
		return p.first > q.first;
	});
	
	ll result = 0;

	for(const auto& p: cord){
		int y = p.second;
		ll r = query(rt, 1, cnt, id[y], 0);
		if(r != 0)
			result += ((tmp[p] * r) % MOD);
		
		update(rt, 1, cnt, id[y], 0);
	}
	printf("%lld\n", result%MOD);

	return 0;
}
