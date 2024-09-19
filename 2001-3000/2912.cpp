#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using pair = std::pair<int, int>;
using std::vector;

constexpr int N = 300001;
constexpr int M = 10001;
constexpr int SN = 550;

int arr[N] = { 0, };
vector<std::pair<pair, int>> query;
int result[M][2] = { 0, };

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
	
	int ps = -1, pe = -1;
	int rn = 0, srn = 0;
	int cnt[M] = { 0, };
	std::unordered_map<int, std::unordered_set<int>> vcnt{};
	for(auto& [p, idx]: query){
		auto& [s, e] = p;
		while(s < ps){
			ps --;
			int cur = arr[ps];

			vcnt[cnt[cur]].erase(cur);
			cnt[cur] ++;
			vcnt[cnt[cur]].insert(cur);

			if(cnt[rn] < cnt[arr[ps]]) rn = arr[ps];
		}
		while(ps < s){
			if(ps != -1){ 
				int cur = arr[ps];

				vcnt[cnt[cur]].erase(cur);
				int nxt = !vcnt[cnt[cur]].empty()?(*vcnt[cnt[cur]].begin()):cur;
				cnt[cur] --;
				vcnt[cnt[cur]].insert(cur);
				
				rn = nxt;
			}
			ps ++;
		}
		while(pe < e){
			pe ++;
			int cur = arr[pe];

			vcnt[cnt[cur]].erase(cur);
			cnt[cur] ++;
			vcnt[cnt[cur]].insert(cur);

			if(cnt[rn] < cnt[arr[pe]]) rn = arr[pe];
		}
		while(e < pe){
			int cur = arr[pe];

			vcnt[cnt[cur]].erase(cur);
			int nxt = !vcnt[cnt[cur]].empty()?(*vcnt[cnt[cur]].begin()):cur;
			cnt[cur] --;
			vcnt[cnt[cur]].insert(cur);
			
			rn = nxt;
			pe --;
		}
		result[idx][0] = rn;
		result[idx][1] = cnt[rn]*2 > (e-s+1);
	}


	for(int i = 0; i < m; i ++){
		if(result[i][1])
			printf("yes %d\n", result[i][0]);
		else
			printf("no\n");
	}

	return 0;
}
