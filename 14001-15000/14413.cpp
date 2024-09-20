#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using pair = std::pair<int, int>;
using std::vector;
using unordered_map = std::unordered_map<int, int>;

constexpr int N = 500001;
constexpr int M = 500001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query{};
unordered_map cnt{};
int result[M] = { 0, };

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
		int prev = cnt[cur];
		cnt[cur] ++;
		if(cnt[cur] == 2) result[query[0].second] ++;
		if(prev == 2 && cnt[cur] > 2) result[query[0].second] --;
	}
	int prev_result = result[query[0].second];

	for(int i = 1; i < query.size(); i ++){
		auto& [p, idx] = query[i];
		auto& [s, e] = p;
		result[idx] = prev_result;
		while(ps < s){
			int cur = arr[ps];
			int prev = cnt[cur];
			cnt[cur] --;	
			if(cnt[cur] == 2) result[idx] ++;
			if(prev == 2 && cnt[cur] < 2) result[idx] --;
			ps ++;
		}
		while(e < pe){
			int cur = arr[pe];
			int prev = cnt[cur];
			cnt[cur] --;	
			if(cnt[cur] == 2) result[idx] ++;
			if(prev == 2 && cnt[cur] < 2) result[idx] --;

			pe --;
		}
		while(pe < e){
			pe ++;
			int cur = arr[pe];
			int prev = cnt[cur];
			cnt[cur] ++;
			if(cnt[cur] == 2) result[idx] ++;
			if(prev == 2 && cnt[cur] > 2) result[idx] --;
		}	
		while(s < ps){
			ps --;
			int cur = arr[ps];
			int prev = cnt[cur];
			cnt[cur] ++;
			if(cnt[cur] == 2) result[idx] ++;
			if(prev == 2 && cnt[cur] > 2) result[idx] --;
		}
		prev_result = result[idx];
	}


	for(int i = 0; i < m; i ++){
		printf("%d\n", result[i]);
	}

	return 0;
}
