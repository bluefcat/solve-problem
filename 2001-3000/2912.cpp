#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using pair = std::pair<int, int>;
using std::vector;

constexpr int N = 300001;
constexpr int M = 10001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
int result[M] = { 0, };

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	
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
			int pidx = p.second/std::sqrt(n);
			int qidx = q.second/std::sqrt(n);
			if(pidx == qidx)
				return p.first < q.first;
			return pidx < qidx;
		}
	);
	
	int ps = query[0].first.first, pe = query[0].first.second;
	int cnt[N] = { 0, };

	for(int i = ps; i <= pe; i ++){
		int cur = arr[i];
		cnt[cur] ++;
	}
	for(int i = 0; i < M; i ++){
		if(cnt[i] * 2 <= (pe-ps+1)) continue;
		result[query[0].second] = i;
		break;
	}

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
		for(int c = 0; c < M; c ++){
			if(cnt[c]*2 <= (e-s+1)) continue;
			result[idx] = c;
			break;
		}
	}


	for(int i = 0; i < m; i ++){
		if(result[i])	
			printf("yes %d\n", result[i]);
		else
			printf("no\n");
	}

	return 0;
}
