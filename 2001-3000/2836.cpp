#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

int main(){
	long long n, m;
	long long result = 0;
	vector<pair<int, int>> cord{};
	scanf("%lld %lld", &n, &m);
	
	int s = 0, e = 0;
	for(int i = 0; i < n; i ++){
		int s, e;
		scanf("%d %d", &s, &e);
		if(s < e) continue;
		cord.push_back({s, e});
	}
	
	if(cord.size() == 0){
		printf("%lld\n", m);
		return 0;
	}

	std::sort(cord.begin(), cord.end(), [](const auto& p, const auto& q){
		return p.first > q.first;
	});
	
	int l = cord[0].second;
	int r = cord[0].first;

	for(auto& [s, e]: cord){
		if(s >= l){
			l = std::min(e, l);
		}
		else{
			result += (r-l)*2;
			l = e; r = s;
		}
	}
	result += (r-l)*2;
	printf("%lld\n", result + m);

	return 0;
}
