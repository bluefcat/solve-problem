#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using ll = long long;
using std::vector;
using std::pair;

constexpr int N = 100001;
constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1) + 2; }

vector<int> graph[N];
int idx[N];
pair<int, int> mapper[N];

ll tree[4*N+4][2] = { 0, };

int build(int& cand, int cur){
	int start = ++cand;
	idx[cur] = start;
	int end = start;

	for(auto next: graph[cur])
		end = std::max(end, build(cand, next));
	
	pair<int, int> result{start, end};
	mapper[cur] = result;
	return end;
}


void propagate(int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] += tree[idx][1];
		tree[get_right(idx)][1] += tree[idx][1];
	}
	tree[idx][0] += tree[idx][1];
	tree[idx][1] = 0;
}

ll update(int l, int r, int s, int e, int w, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] += w;
		propagate(l, r, idx);
		return tree[idx][0];
	}
	int m = (l + r) >> 1;
	ll lr = update(l, m, s, e, w, get_left(idx));
	ll rr = update(m+1, r, s, e, w, get_right(idx));
	return tree[idx][0] = lr + rr;
}

ll query(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) 
		return tree[idx][0];
	
	int m = (l + r) >> 1;
	return query(l, m, s, e, get_left(idx)) + query(m+1, r, s, e, get_right(idx));
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++){
		int v;
		scanf("%d", &v);
		if(v == -1) continue;
		graph[v].push_back(i);
	}
	int id = -1;
	build(id, 1);
	for(int i = 0; i < m; i ++){
		int oper, x, w;
		scanf("%d %d", &oper, &x);
		switch(oper){
			case 1:
				scanf("%d", &w);
				update(0, id, mapper[x].first, mapper[x].first, w, 0);
			break;
			case 2:
				w = query(0, id, mapper[x].first, mapper[x].second, 0);
				printf("%d\n", w);
			break;
		}
	}

	return 0;
}
