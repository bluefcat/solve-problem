#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>

using ll = long long;
using set = std::unordered_set<ll>;
using map = std::unordered_map<ll, ll>;
using vector = std::vector<ll>;
using query = std::vector<std::tuple<ll, ll, ll>>;

constexpr int N = 400001;
constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1) + 2; }
ll tree[4*N+4][2] = { 0, };
ll height[N] = { 0, };

ll update(int l, int r, int s, int e, bool oper, int idx){
	if(r < s || e < l) return 0;
	
	if(s <= l && r <= e){
		tree[idx][1] += oper?1:-1;
	}
	else{
		int m = (l + r) >> 1;
		update(l, m, s, e, oper, get_left(idx));
		update(m+1, r, s, e, oper, get_right(idx));
	}

	if(tree[idx][1]){
		tree[idx][0] = height[r+1] - height[l];
	}
	else{
		if(l == r) return tree[idx][0] = 0;
		return tree[idx][0] = tree[get_left(idx)][0] + tree[get_right(idx)][0];
	}
	return 0;	
}

set hset{};
map hmap{};

query adder{};
query suber{};

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		ll x0, x1, y0, y1;
		scanf("%lld %lld %lld %lld", &x0, &x1, &y0, &y1);
		hset.insert(y0); hset.insert(y1);
		adder.push_back(std::make_tuple(x0, y0, y1));
		suber.push_back(std::make_tuple(x1, y0, y1));
	}
	vector tmp{hset.begin(), hset.end()};
	std::sort(tmp.begin(), tmp.end());

	for(int i = 0; i < tmp.size(); i ++){
		hmap[tmp[i]] = i;
		height[i] = tmp[i];
	}

	std::sort(
		adder.begin(), 
		adder.end(), 
		[](auto& p, auto& q){
			auto& [xp0, yp0, yp1] = p;
			auto& [xq0, yq0, yq1] = q;
			return xp0 < xq0;
		}
	);

	std::sort(
		suber.begin(), 
		suber.end(), 
		[](auto& p, auto& q){
			auto& [xp0, yp0, yp1] = p;
			auto& [xq0, yq0, yq1] = q;
			return xp0 < xq0;
		}
	);

	ll result = 0;
	ll px = 0, ph = 0;
	int ai = 0, si = 0;
	ll x0, y0, y1;

	while(ai < adder.size() || si < suber.size()){
		auto [x0, y0, y1] = adder[ai];
		auto [sx0, sy0, sy1] = suber[si];
		bool oper = true;

		if(sx0 < x0 || ai >= adder.size()){
			x0 = sx0; y0 = sy0; y1 = sy1; oper = false;
			si ++;
		}
		else{
			ai ++;
		}

		update(0, 2*n, hmap[y0], hmap[y1]-1, oper, 0);
		ll a = px, b = ph;
		result += (x0 - px) * ph;
		ll h = tree[0][0];
		px = x0;
		ph = h;
	}


	printf("%lld\n", result);

	return 0;
}
