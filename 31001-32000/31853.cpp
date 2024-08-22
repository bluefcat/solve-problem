#include <assert.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::pair;
using std::vector;
using ll = long long;

constexpr int N = 10001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }

bool compare(pair<ll, ll>& x, pair<ll, ll>& y){
	if(x.second == y.second) 
		return x.first < y.first;
	return x.second < y.second;
}

ll update(ll tree[], int l, int r, int k, int idx){
	if(!(l <= k && k <= r)) return tree[idx];
	if(l == r) return tree[idx] += 1;
	int m = (l + r) >> 1;
	return tree[idx] = update(tree, l, m, k, get_left(idx)) +
					   update(tree, m+1, r, k, get_right(idx));
}

ll query(ll tree[], int l, int r, ll s, ll e, int idx){
	if(r <= s || e <= l) return 0;
	if(s < l && r < e) return tree[idx];
	int m = (l + r) >> 1;
	return query(tree, l, m, s, e, get_left(idx)) + 
		   query(tree, m+1, r, s, e, get_right(idx));
}


int main(){
	ll n, m;
	vector<ll> dict{};
	std::unordered_map<ll, ll> pos{};
	vector<pair<ll, ll>> line{};
	scanf("%lld %lld", &n, &m);
	assert(2 <= n && n <= 1000000000);
	for(ll i = 0; i < m; i ++){
		ll u, v;
		scanf("%lld %lld", &u, &v);
		assert(u != v);
		assert(u <= n);
		assert(v <= n);
		if(u > v){
			ll tmp = u; u = v; v = tmp;
		}
		dict.push_back(u);
		dict.push_back(v);

		line.push_back({u, v});
	}
	std::sort(dict.begin(), dict.end());
	std::sort(line.begin(), line.end(), compare);

	for(int i = 0; i < dict.size(); i ++){
		pos[dict[i]] = i;
	}

	ll result = 0;
	for(int i = 2; i < line.size(); i ++){
		auto& [u, v] = line[i];
		ll u_id = pos[u];
		ll tree[4*N+4] = { 0, };
		for(int j = i-1; j >=0; j --){
			auto& [p, q] = line[j];
			if(!((p < u) && (u < q && q < v))) continue;
			ll p_id = pos[p];
			ll pl = query(tree, 0, N-1, p_id, u_id, 0);
			result += pl;
			update(tree, 0, N-1, p_id, 0);
		}
	}
	printf("%lld\n", result);
	return 0;

}
