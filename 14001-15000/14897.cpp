#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using pair = std::pair<int, int>;
using std::vector;
using lint = long long;

constexpr int N = 1000001;
constexpr int M = 1000001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
int result[M] = { 0, };
std::unordered_map<lint, int> cnt{};

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++)
		scanf("%d", arr + i);

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int s, e;
		scanf("%d %d", &s, &e);
		query.push_back({{s-1, e-1}, i});
	}

	std::sort(
		query.begin(), query.end(),
		[&](const std::pair<pair, int>& x, const std::pair<pair, int>& y){
			auto& p = x.first;
			auto& q = y.first;
			int pidx = p.second/2000;//std::sqrt(n);
			int qidx = q.second/2000;//std::sqrt(n);
			if(pidx == qidx)
				return p.first < q.first;
			return pidx < qidx;
		}
	);
	
	int ps = query[0].first.first, pe = query[0].first.second;
	int pidx = query[0].second;
	for(int i = ps; i <= pe; i ++){
		int cur = arr[i];
		if(cnt[cur] == 0) result[pidx] ++;
		cnt[cur] ++;
	}

	for(int i = 1; i < query.size(); i ++){
		auto& [p, idx] = query[i];
		auto& [s, e] = p;
		result[idx] = result[pidx];
		while(ps < s){
			int cur = arr[ps];
			
			cnt[cur] --;
			if(cnt[cur] == 0) result[idx] --;
			ps ++;
		}
		while(e < pe){
			int cur = arr[pe];
			cnt[cur] --;
			if(cnt[cur] == 0) result [idx] --;
			pe --;
		}
		while(pe < e){
			pe ++;
			int cur = arr[pe];
			if(cnt[cur] == 0) result[idx] ++;
			cnt[cur] ++;
		}	
		while(s < ps){
			ps --;
			int cur = arr[ps];
			if(cnt[cur] == 0) result[idx] ++;
			cnt[cur] ++;
		}
		pidx = idx;
	}


	for(int i = 0; i < m; i ++){
		printf("%d\n", result[i]);
	}

	return 0;
}
