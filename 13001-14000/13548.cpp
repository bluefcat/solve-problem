#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using pair = std::pair<int, int>;
using std::vector;

constexpr int N = 100001;
constexpr int M = 100001;
constexpr int SN = 550;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
int result[M] = { 0, };

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
			int pidx = p.second/std::sqrt(n);
			int qidx = q.second/std::sqrt(n);
			if(pidx == qidx)
				return p.first < q.first;
			return pidx < qidx;
		}
	);
	
	int ps = -1, pe = -1;
	int rn = -1;
	int cnt[N] = { 0, };
	for(auto& [p, idx]: query){
		auto& [s, e] = p;
		while(ps < s){
			if(ps != -1) cnt[arr[ps]] --;
			ps ++;
		}
		while(e < pe){
			cnt[arr[pe]] --;
			pe --;
		}
		while(pe < e){
			pe ++;
			cnt[arr[pe]] ++;
			if(cnt[rn] < cnt[arr[pe]]) rn = arr[pe];
		}	
		while(s < ps){
			ps --;
			cnt[arr[ps]] ++;
			if(cnt[rn] < cnt[arr[ps]]) rn = arr[ps];
		}
		result[idx] = cnt[rn];
		ps = s, pe = e;
	}


	for(int i = 0; i < m; i ++){
		printf("%d\n", result[i]);
	}

	return 0;
}
