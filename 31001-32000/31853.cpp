#include <cstdio>
#include <vector>
#include <algorithm>

using std::pair;
using std::vector;
using ll = long long;

constexpr int N = 20001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }

bool compare(pair<int, int>& x, pair<int, int>& y){
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

ll query(ll tree[], int l, int r, int s, int e, int idx){
	if(r <= s | e <= l) return 0;
	if(s < l && r < e) return tree[idx];
	int m = (l + r) >> 1;
	return query(tree, l, m, s, e, get_left(idx)) + 
		   query(tree, m+1, r, s, e, get_right(idx));
}


int main(){
	int n, m;
	vector<int> dict{};
	vector<pair<int, int>> line{};
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v){
			int tmp = u; u = v; v = tmp;
		}
		dict.push_back(u);
		dict.push_back(v);

		line.push_back({u, v});
	}
	std::sort(dict.begin(), dict.end());
	std::sort(line.begin(), line.end(), compare);

	ll result = 0;
	for(int i = 0; i < line.size(); i ++){
		auto& [u, v] = line[i];
		int u_id = std::upper_bound(dict.begin(), dict.end(), u) - dict.begin();
		ll tree[4*N+4] = { 0, };
		for(int j = i-1; j >=0; j --){
			auto& [p, q] = line[j];
			if(!((p < u) && (u < q && q < v))) continue;
			int p_id = std::upper_bound(dict.begin(), dict.end(), p) - dict.begin();
			ll pl = query(tree, 0, 2*m, p_id, u_id, 0);
			result += pl;
			update(tree, 0, 2*m, p_id, 0);
		}
	}
	printf("%lld\n", result);
	return 0;

}
