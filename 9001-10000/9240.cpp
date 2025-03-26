#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>

using std::vector;
using std::deque;
using ll = double;
using pair = std::pair<ll, ll>;

bool compare(pair& p, pair& q, pair& b){
	ll px = p.first - b.first, py = p.second - b.second;
	ll qx = q.first - b.first, qy = q.second - b.second;
	if(py*qx != px*qy) return py*qx < px*qy;
	if(py != qy) return py < qy;
	return px < qx;
}

ll ccw(pair& p, pair& q, pair& r){
	return (q.first - p.first)*(r.second - p.second) -
		   (q.second - p.second)*(r.first - p.first);
}

ll cccw(pair& p, pair& q, pair& r, pair& k){
	pair base{
		k.first - (r.first - q.first),
		k.second - (r.second - q.second)
	};
	return ccw(p, q, base);
}

ll get_square(pair& p, pair& q){
	return (p.first - q.first) * (p.first - q.first) +
		   (p.second - q.second) * (p.second - q.second);
}

int main(){
	int n;
	vector<pair> pos{};
	scanf("%d", &n);
	for(int i = 0 ; i < n; i ++){
		ll x, y;
		scanf("%lf %lf", &x, &y);
		pos.push_back({x, y});
	}

	std::sort(
		pos.begin(), 
		pos.end(),
		[](pair& p, pair q){
			if(p.second != q.second) return p.second < q.second;
			return p.first < q.first;
		}
	);

	std::sort(
		pos.begin() + 1,
		pos.end(),
		[&](pair& p, pair q){ return compare(p, q, pos[0]); }
	);

	deque<pair> s{};
	s.push_back(pos[0]);
	s.push_back(pos[1]);
		
	for(int i = 2; i < n; i ++){
		while(s.size() >= 2){
			pair q = s.back(); s.pop_back();
			pair p = s.back();
			if(ccw(p, q, pos[i]) > 0){
				s.push_back(q);
				break;
			}
        }
		s.push_back(pos[i]);
	}

	ll result = 0;
	int length = s.size();

	pair p{}, q{};

	for(int i = 0, j = 1; i < length; i ++){
		while(
			(j+1) != i && 
			cccw(s[i], s[i+1], s[j%length], s[(j+1)%length]) > 0
		){	
			if(result < get_square(s[i], s[j%length])){
				p = s[i];
				q = s[j%length];
				result = get_square(p, q); 
			}
			j++;
		}
		if(result < get_square(s[i], s[j%length])){
			p = s[i];
			q = s[j%length];
			result = get_square(p, q); 
		}
	}
	printf("%lf\n", std::sqrt(result));
	return 0;
}
