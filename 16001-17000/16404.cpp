#include <cstdio>
#include <unordered_map>
#include <vector>
#include <utility>

using std::unordered_map, std::vector;
using std::pair;
using lint = long long;

constexpr int N = 100001;
constexpr int get_left(int idx){
	return (idx << 1) + 1;
}
constexpr int get_right(int idx){
	return (idx << 1) + 2;
}

template<typename T, typename U>
int build(T& graph, int& id, int cur, U& mapper){
	int start = ++id;	
	int end = start;

	for(auto next: graph[cur]){
		end = build(graph, id, next, mapper);
	}
	mapper[cur] = {start, end};
	return end;
}

lint tree[4*N+4][2] = { 0, };

void propagate(int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] += tree[idx][1];
		tree[get_right(idx)][1] += tree[idx][1];
	}
	tree[idx][0] += tree[idx][1];
	tree[idx][1] = 0;
}

lint update(int l, int r, int s, int e, lint w, int idx){
	propagate(l, r, idx);
	if(r < s | e < l) return 0;
	if(s <= l && r <= e){
		tree[idx][1] += w;
		propagate(l, r, idx);
		return tree[idx][0];
	}
	int m = (l + r) >> 1;
	lint lr = update(l, m, s, e, w, get_left(idx));
	lint rr = update(m+1, r, s, e, w, get_right(idx));

	return tree[idx][0] = lr + rr;
}

lint query(int l, int r, int q, int idx){
	propagate(l, r, idx);
	if(l == r) return tree[idx][0];

	int m = (l + r) >> 1;
	if(q <= m) return query(l, m, q, get_left(idx));
	return query(m+1, r, q, get_right(idx));
}

int main(){
	unordered_map<int, vector<int>> graph{};
	vector<pair<int, int>>mapper(N); // [start, end]
	int n, m, id = -1;
	scanf("%d %d", &n, &m);
	//imployee number [0, n-1]		
	for(int i = 0; i < n; i ++){
		int u;
		scanf("%d", &u);
		if(u == -1) continue;
		graph[u-1].push_back(i);
	}
	build(graph, id, 0, mapper);
	
	for(int c = 0; c < m; c ++){
		int oper, i;
		lint w;
		scanf("%d %d", &oper, &i);
		switch(oper){
			case 1:
				scanf("%lld", &w);
				update(0, n-1, mapper[i-1].first, mapper[i-1].second, w, 0);
				break;
			case 2:
				printf("%lld\n", query(0, n-1, mapper[i-1].first, 0));
				break;
		}
	}

	return 0;
}
