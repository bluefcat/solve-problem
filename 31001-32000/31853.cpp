#include <assert.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::pair;
using std::vector;
using ll = long long;

constexpr int N = 7001;

bool compare(pair<int, int>& x, pair<int, int>& y){
	return x.second < y.second;
}

ll tree[4*N+4] = { 0, };

ll update(int l, int r, int k, int idx){
	ll result = 0;
	while(l < r){
		int m = (l + r) >> 1;
		if(k <= m){
			result += tree[((idx << 1) + 2)];
			idx = (idx << 1) + 1;
			r = m;
		}
		else{
			idx = (idx << 1) + 2;
			l = m+1;
		}
	}
	result += tree[idx];
	while(idx != 0){
		tree[idx] ++;
		idx = (idx-1) >> 1;
	}
	tree[0] ++;
	return result;
}

int main(){
	int n, m;
	vector<int> udict{};
	std::unordered_map<int, int> upos{};
	vector<pair<int, int>> line{};
	vector<int> liner{};
	n = 13998;
	m = 6999;
	//scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v;
		u = i+1;
		v = m+1+i;
		//scanf("%d %d", &u, &v);
		if(u > v){
			ll tmp = u; u = v; v = tmp;
		}
		udict.push_back(u);
		line.push_back({u, v});
	}
	std::sort(udict.begin(), udict.end());
	std::sort(line.begin(), line.end(), compare);
	for(int i = 0; i < m; i ++) upos[udict[i]] = i;
	
	ll result = 0;
	for(int i = 2; i < m; i ++){
	    int u_id = upos[line[i].first];
		for(int j = 0; j < 4*N+4; j ++) tree[j] = 0;
		for(int j = i-1; j >=0; j --){
			int p_id = upos[line[j].first];
			if(p_id < u_id && line[i].first < line[j].second){ 
				result += update(0, N, p_id, 0);
			}
		}
	}
	printf("%lld\n", result);
	return 0;

}
