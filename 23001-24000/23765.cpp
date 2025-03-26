#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using std::vector;
using std::pair;
using std::deque;

using ll = long long;

bool compare_without_base(pair<ll, ll>& p, pair<ll, ll>& q){
	if(p.second != q.second) return p.second < q.second;
	return p.first < q.first;
}

bool compare(pair<ll, ll>& p, pair<ll, ll>& q, pair<ll, ll>& b){
	ll px = (p.first - b.first);
	ll py = (p.second - b.second);
	ll qx = (q.first - b.first);
	ll qy = (q.second - b.second);
	if(px * qy != py * qx)
		return py * qx < px * qy;
	if(p.second != q.second) return p.second < q.second;
	return p.first < q.first;
}

template<typename T = pair<ll, ll>>
ll ccw(T& p, T& q, T& r){
	return (q.first - p.first) * (r.second - p.second) -
		   (q.second - p.second) * (r.first - p.first);
}

int main(){
	pair<ll, ll> o{0, 0};
	vector<pair<ll, ll>> pos{};
	deque<pair<ll, ll>> s{};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		pos.push_back({x, y});
	}

	std::sort(
		pos.begin(), 
		pos.end(),
		compare_without_base
	);

	std::sort(
		pos.begin()+1, 
		pos.end(),
		[&](pair<ll, ll>& x, pair<ll, ll>& y){ return compare(x, y, pos[0]); }
	);

	s.push_back(pos[0]);
	s.push_back(pos[1]);

	for(int i = 2; i < pos.size(); i ++){
		while(s.size() >= 2){
			pair<ll, ll> p = s.back(); s.pop_back();
			pair<ll, ll> q = s.back();

			if(ccw(q, p, pos[i]) > 0){
				s.push_back(p);
				break;
			}
		}
		s.push_back(pos[i]);
	}
	
	double result = 0;
	pair<ll, ll> base = s[0];

	for(int i = 1; i < s.size()-1; i ++){
		double tmp = std::abs(ccw(base, s[i], s[i+1]));
		result += tmp/2.0;
	}
	printf("%lf\n", result);

	return 0;
}
