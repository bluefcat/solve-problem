#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <tuple>

using ll = long long;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::tuple;

constexpr int N = 200001;
constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1) + 2; }

ll arr[N] = { 0, };
ll tree[4*N+4][2] = { 0, };
vector<ll> hv{};

void update(int l, int r, int s, int e, bool oper, int idx){
	if(r < s | e < l) return;
	if(s <= l && r <= e){
		tree[idx][1] += oper?1:-1;
	}
	else{
		int m = (l + r) >> 1;
		if(s <= m){
			update(l, m, s, e, oper, get_left(idx));
		}
		if(e >= m+1){ 
			update(m+1, r, s, e, oper, get_right(idx));
		}
	}
	if(tree[idx][1]){
		tree[idx][0] = hv[r+1] - hv[l];
	}
	else{
	if(l == r) tree[idx][0] = 0;
	else
		tree[idx][0] = tree[get_left(idx)][0] + tree[get_right(idx)][0];

	}
}

unordered_set<ll> height{};
unordered_map<ll, ll> hidx{};
vector<tuple<bool, ll, ll, ll>> q{};

int main(){
	int n;
	//n = 10000;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		ll x0, x1, y0, y1;
		//x0 = 0; x1 = 30000; y0 = 0; y1 = 30000;
		//x0 = i; x1 = i+1; y0 = 0; y1 = i+1;
		scanf("%lld %lld %lld %lld", &x0, &y0, &x1, &y1);
		height.insert(y0);
		height.insert(y1);
		q.push_back(std::make_tuple(true, x0, y0, y1));
		q.push_back(std::make_tuple(false, x1, y0, y1));
	}	
	vector<ll> tmp{height.begin(), height.end()};
	std::sort(tmp.begin(), tmp.end());

	for(int i = 0; i < tmp.size(); i ++){
		hidx[tmp[i]] = i;
		if(i < tmp.size()-1) arr[i] = tmp[i+1] - tmp[i];
	}
	hv.assign(tmp.begin(), tmp.end());

	std::sort(
		q.begin(), 
		q.end(), 
		[](tuple<bool, ll, ll, ll>& p, tuple<bool, ll, ll, ll>& q){
			auto& [operp, xp0, yp0, yp1] = p;
			auto& [operq, xq0, yq0, yq1] = q;
			return !(xp0 > xq0) && !(xp0==xq0 && operp < operq);
		}
	);

	ll result = 0;
	ll px = 0, ph = 0;
	for(auto& [oper, x0, y0, y1]: q){
		update(0, n, hidx[y0], hidx[y1]-1, oper, 0);
		ll a = px, b = ph;
		result += (x0 - px) * ph;
		ll height = tree[0][0];
		px = x0;
		ph = height;
	}
	printf("%lld\n", result);
	return 0;
}
