#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using pair = std::pair<int, int>;
using std::vector;

constexpr int N = 100001;
constexpr int M = 100001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query{};
int result[M] = { 0, };
int vnt[N] = { 0, };

int main(){
	while(true){
		for(int i = 0; i < N; i ++){
			arr[i] = 0; vnt[i] = 0;
		}
		for(int i = 0; i < M; i ++) result[i] = 0;
		query.clear();
		int n, m;
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d", &m);
		
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
		int rn = 1;
		int cnt[2*N] = { 0, };
		cnt[arr[ps]+N] = 1;
		vnt[1] = 1;

		for(int i = ps+1; i <= pe; i ++){
			int cur = arr[i]+N;
			vnt[cnt[cur]] --;
			cnt[cur] ++;
			vnt[cnt[cur]] ++;
			if(rn < cnt[cur]) rn = cnt[cur];
		}
		result[query[0].second] = rn;

		for(int i = 1; i < query.size(); i ++){
			auto& [p, idx] = query[i];
			auto& [s, e] = p;
			while(ps < s){
				int cur = arr[ps]+N;
				
				vnt[cnt[cur]] --;
				if(vnt[cnt[cur]] == 0 && rn == cnt[cur]) rn --; 
				cnt[cur] --;
				vnt[cnt[cur]]++;
				ps ++;
			}
			while(e < pe){
				int cur = arr[pe]+N;

				vnt[cnt[cur]] --;
				if(vnt[cnt[cur]] == 0 && rn == cnt[cur]) rn --;
				cnt[cur] --;
				vnt[cnt[cur]] ++;
				pe --;
			}
			while(pe < e){
				pe ++;
				int cur = arr[pe]+N;
				vnt[cnt[cur]] --;
				cnt[cur] ++;
				vnt[cnt[cur]] ++;
				if(rn < cnt[cur]) rn = cnt[cur];
			}	
			while(s < ps){
				ps --;
				int cur = arr[ps]+N;
				vnt[cnt[cur]] --;
				cnt[cur] ++;
				vnt[cnt[cur]] ++;
				if(rn < cnt[cur]) rn = cnt[cur];
			}
			result[idx] = rn;
		}


		for(int i = 0; i < m; i ++){
			printf("%d\n", result[i]);
		}
	}
	return 0;
}
