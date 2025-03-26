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
	deque<pair> s{};
	scanf("%d", &n);
	for(int i = 0 ; i < n; i ++){
		ll x, y;
		scanf("%lf %lf", &x, &y);
		s.push_back({x, y});
	}

	ll result = 10000000.f;
	int length = s.size();

	pair p{}, q{};
	
	for(int k = 0; k < length; k ++){
		ll tmp = 0;
		for(int i = k, j = k+1; i < length; i ++){
			while(
				(j+1) != i && 
				cccw(s[i], s[i+1], s[j%length], s[(j+1)%length]) > 0
			){	
				if(tmp < get_square(s[i], s[j%length])){
					p = s[i];
					q = s[j%length];
					tmp = get_square(p, q); 
				}
				j++;
			}
			if(tmp < get_square(s[i], s[j%length])){

				p = s[i];
				q = s[j%length];
				tmp = get_square(p, q); 
			}
			printf("[%.2lf]\n", std::sqrt(tmp));
		}
		result = std::min(result, tmp);
	}
	printf("%lf\n", std::sqrt(result));
	return 0;
}
