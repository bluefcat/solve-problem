#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using pair = std::pair<int, int>;
using std::vector;
using lint = long long;

constexpr int N = 100001;
constexpr int M = 100001;
constexpr int A = 1000001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
lint result[M] = { 0, };
int cnt[A] = { 0, };

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i ++)
		scanf("%d", arr + i);

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
			int pidx = p.second/std::sqrt(n);
			int qidx = q.second/std::sqrt(n);
			if(pidx == qidx)
				return p.first < q.first;
			return pidx < qidx;
		}
	);
	
	int ps = query[0].first.first, pe = query[0].first.second;

	for(int i = ps; i <= pe; i ++){
		int cur = arr[i];
		cnt[cur] ++;
	}
	for(int i = ps; i <= pe; i ++)
		result[query[0].second] += arr[i] * cnt[arr[i]];
	
	for(int i = 1; i < query.size(); i ++){
		auto& [p, idx] = query[i];
		auto& [s, e] = p;
		while(ps < s){
			int cur = arr[ps];
			cnt[cur] --;
			ps ++;
		}
		while(e < pe){
			int cur = arr[pe];
			cnt[cur] --;
			pe --;
		}
		while(pe < e){
			pe ++;
			int cur = arr[pe];
			cnt[cur] ++;
		}	
		while(s < ps){
			ps --;
			int cur = arr[ps];
			cnt[cur] ++;
		}
		for(int j = ps; j <= pe; j++)
			result[idx] += cnt[arr[j]] * arr[j];
		
	}


	for(int i = 0; i < m; i ++){
		printf("%lld\n", result[i]);
	}

	return 0;
}
