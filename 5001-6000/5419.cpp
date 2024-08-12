#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::pair;
using std::unordered_map;
using ll = long long;

constexpr int N = 75001;
constexpr int get_left(int x){
	return ((x) << 1) + 1;
}
constexpr int get_right(int x){
	return ((x) << 1) + 2;
}

ll update(ll* tree, int l, int r, int k, int idx){
	if(!(l <= k && k <= r)) return tree[idx];
	if(l == r) return tree[idx] = tree[idx]+1;

	int m = (l + r) >> 1;
	ll lr = update(tree, l, m, k, get_left(idx));
	ll rr = update(tree, m+1, r, k, get_right(idx));
	return tree[idx] = lr+rr;
}

ll query(ll* tree, int l, int r, int s, int idx){
	if(r < s) return 0;
	if(s <= l) return tree[idx];
	int m = (l + r) >> 1;
	return query(tree, l, m, s, get_left(idx)) +
		   query(tree, m+1, r, s, get_right(idx));
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		vector<pair<int, int>> cord{};
		unordered_map<int, int> id{};
		ll tree[4*N+4] = { 0, };
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			int x, y;
			scanf("%d %d", &x, &y);
			cord.push_back({x, y});
		}
		
		std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
			return p.second <= q.second;
		});

		int cnt = 0;
		for(auto& [_, y]: cord){
			if(id[y] == 0) id[y] = ++cnt;
		}	

		std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
			if(p.first < q.first) return true;
			if(p.first == q.first) return p.second > q.second;
			return false;
		});
		ll result = 0;
		for(auto& [x, y]: cord){
			ll r = query(tree, 1, cnt, id[y], 0);
			result += r;
			update(tree, 1, cnt, id[y], 0);
		}
		printf("%lld\n", result);

	}
	return 0;
}
