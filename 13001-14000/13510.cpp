#include <cstdio>
#include <unordered_map>
#include <vector>
#include <utility>

using lint = long long;
using std::unordered_map;
using std::vector;
using edge = std::pair<lint, lint>;

constexpr int N = 100001;
constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1 ) + 2; }

lint arr[N] = { 0, };
lint tree[4*N+4][2] = { 0, };

void propagate(int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l+1 != r){
		tree[get_left(idx)][1] = std::max(tree[get_left(idx)][1], tree[idx][1]);
		tree[get_right(idx)][1] = std::max(tree[get_right(idx)][1], tree[idx][1]);
	}
	tree[idx][0] = std::max(tree[idx][0], tree[idx][1]);
	tree[idx][1] = 0;
}

lint init(int l, int r, int idx){
	if(l >= r) return 0;
	if(l+1 == r) return tree[idx][0] = arr[r];
	int m = (l + r) >> 1;
	return tree[idx][0] = std::max(init(l, m+1, get_left(idx)), init(m, r, get_right(idx)));
}

lint update(int l, int r, int s, int e, lint k, int idx){
	propagate(l, r, idx);
	if(r <= s || e < l) return tree[idx][0];
	if(s < l && r <= e){
		tree[idx][1] += k;
		propagate(l, r, idx);
		return tree[idx][0];
	}
	
	int m = (l + r) >> 1;
	return tree[idx][0] = std::max(update(l, m, s, e, k, get_left(idx)),
						  update(m, r, s, e, k, get_right(idx)));
}

lint _query(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r <= s || e < l) return 0;
	if(s < l && r <= e){
		return tree[idx][0];
	}
	int m = (l + r) >> 1;
	lint ll = _query(l, m, s, e, get_left(idx));
	lint lr = _query(m, r, s, e, get_right(idx));
	return std::max(ll, lr);
}


struct node{
	lint size;
	lint depth;
	lint parent;
	lint top;
	lint in, out;
};

unordered_map<lint, node> info{};
//edge -> next_edge;
unordered_map<lint, vector<lint>> graph{};
unordered_map<lint, vector<edge>> input{};
unordered_map<lint, unordered_map<lint, lint>> id_mapper{};
unordered_map<lint, lint> edge_mapper{};
unordered_map<lint, lint> weight;
bool check[N] = { false, };

void get_graph(lint cur){
	check[cur] = true;
	for(auto [next, w]: input[cur]){
		if(check[next]) continue;
		check[next] = true;
		graph[cur].push_back(next);
		edge_mapper[id_mapper[cur][next]] = { next };
		weight[next] = w;
		get_graph(next);
	}
}

void dfs1(lint cur){
	info[cur].size = 1;	

	for(auto& next: graph[cur]){
		info[next].depth = info[cur].depth + 1;
		info[next].parent = cur;
		
		dfs1(next);
		info[cur].size += info[next].size;
		
		//graph[cur][0] is most heaviler in cur's subtree
		if(info[next].size > info[graph[cur][0]].size)
			std::swap(graph[cur][0], next);
	}
	return;
}

void dfs2(lint& id, lint cur){
	info[cur].in = ++id;
	arr[info[cur].in] = weight[cur];
	for(auto next: graph[cur]){
		info[next].top = next;
		//if 'next' is most heavy in cur's subtree, 'next''s top is cur's top
		if(next == graph[cur][0])
			info[next].top = info[cur].top;
		dfs2(id, next);
	}

	info[cur].out = id;
}

lint query(lint u, lint v){
	lint result = 0;
	while(info[u].top ^ info[v].top){ //not equal
		lint ut = info[u].top, vt = info[v].top;
		
		if(info[ut].depth < info[vt].depth) std::swap(u, v);
		lint start = info[u].top;
		result = std::max(_query(0, N-1, info[start].in, info[u].in, 0), result);
		u = info[start].parent;
	}
	if(info[u].depth > info[v].depth) std::swap(u, v);
	return std::max(result, _query(0, N-1, info[u].in, info[v].in, 0));
}


int main(){
	int n, m;
	lint id = 0, start = 0;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++){
		lint u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		if(i == 0) start = u;
		input[u].push_back({v, w});
		input[v].push_back({u, w});
		id_mapper[u][v] = i;
		id_mapper[v][u] = i;
	}

	get_graph(start);
	dfs1(start);
	dfs2(id, start);
	init(0, N-1, 0);

	printf("---\n");
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		lint oper, u, v, result;
		scanf("%lld %lld %lld", &oper, &u, &v);
		switch(oper){
			case 1:
				u = edge_mapper[u-1];
				update(0, N-1, info[u].in, info[u].in, v, 0);
			break;
			case 2:
				result = query(u, v);
				printf("%lld\n", result);
			break;
		}
	}
	
	return 0;
}
