#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using pair = std::pair<int, int>;
using std::vector;

constexpr int N = 300001;
constexpr int M = 10001;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
int result[M][2] = { 0, };
std::unordered_set<int> vnt[N];

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
	int rn = 0;
	int cnt[N] = { 0, };

	for(int i = ps; i <= pe; i ++){
		int cur = arr[i];
		if(auto iter = vnt[cnt[cur]].find(cur); iter != vnt[cnt[cur]].end())
			vnt[cnt[cur]].erase(cur);
		cnt[cur] ++;
		vnt[cnt[cur]].insert(cur);
		if(cnt[rn] < cnt[cur]) rn = cur;
	}
	result[query[0].second][0] = rn;
	result[query[0].second][1] = 2*cnt[rn] > (pe-ps+1);

	for(int i = 1; i < query.size(); i ++){
		auto& [p, idx] = query[i];
		auto& [s, e] = p;
		while(ps < s){
			int cur = arr[ps];
			
			if(auto iter = vnt[cnt[cur]].find(cur); iter != vnt[cnt[cur]].end())
				vnt[cnt[cur]].erase(cur);
			if(!vnt[cnt[cur]].empty()){ 
				rn = (*vnt[cnt[cur]].begin());
			}
			cnt[cur] --;
			vnt[cnt[cur]].insert(cur);
			ps ++;
		}
		while(e < pe){
			int cur = arr[pe];

			if(auto iter = vnt[cnt[cur]].find(cur); iter != vnt[cnt[cur]].end())
				vnt[cnt[cur]].erase(cur);
			if(!vnt[cnt[cur]].empty()){ 
				rn = (*vnt[cnt[cur]].begin());
			}
			cnt[cur] --;
			vnt[cnt[cur]].insert(cur);
			pe --;
		}
		while(pe < e){
			pe ++;
			int cur = arr[pe];
			if(auto iter = vnt[cnt[cur]].find(cur); iter != vnt[cnt[cur]].end())
				vnt[cnt[cur]].erase(cur);
			cnt[cur] ++;
			vnt[cnt[cur]].insert(cur);
			if(cnt[rn] < cnt[cur]) rn = cur;
		}	
		while(s < ps){
			ps --;
			int cur = arr[ps];
			if(auto iter = vnt[cnt[cur]].find(cur); iter != vnt[cnt[cur]].end())
				vnt[cnt[cur]].erase(cur);
			cnt[cur] ++;
			vnt[cnt[cur]].insert(cur);
			if(cnt[rn] < cnt[cur]) rn = cur;
		}
		result[idx][0] = rn;
		result[idx][1] = 2*cnt[rn] > (e-s+1);
	}


	for(int i = 0; i < m; i ++){
		if(result[i][1])	
			printf("yes %d\n", result[i][0]);
		else
			printf("no\n");
	}

	return 0;
}
