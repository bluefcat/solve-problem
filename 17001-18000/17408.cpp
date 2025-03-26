#include <cstdio>
#include <algorithm>

using lint = long long;

constexpr int N = 100001;
constexpr int get_left(int idx){
	return (idx << 1) + 1;
}
constexpr int get_right(int idx){
	return (idx << 1) + 2;
}

lint arr[N];
//0: max, 1: smax
lint tree[4*N+4][2];

lint* init(int l, int r, int idx){
	if(l == r){ 
		tree[idx][0] = arr[l];
		tree[idx][1] = 0;
		return tree[idx];
	}
	int m = (l + r) >> 1;
	lint *prev = nullptr, *next = nullptr;
	prev = init(l, m, get_left(idx));
	next = init(m+1, r, get_right(idx));
	tree[idx][0] = std::max(prev[0], next[0]);
	if(prev[0] == next[0])
		tree[idx][1] = prev[0];
	else if(prev[0] > next[0])
		tree[idx][1] = std::max(prev[1], next[0]);
	else
		tree[idx][1] = std::max(prev[0], next[1]);
	return tree[idx];
}
lint* update(int l, int r, int k, int v, int idx){
	if(l == r){ 
		tree[idx][0] = v;
		tree[idx][1] = 0;
		return tree[idx];
	}
	int m = (l + r) >> 1;
	lint *prev = nullptr, *next = nullptr;
	if(k <= m){
		prev = tree[get_right(idx)];
		next = update(l, m, k, v, get_left(idx));
	}
	else{
		prev = tree[get_left(idx)];
		next = update(m+1, r, k, v, get_right(idx));
	}
	tree[idx][0] = std::max(prev[0], next[0]);
	if(prev[0] == next[0])
		tree[idx][1] = prev[0];
	else if(prev[0] > next[0])
		tree[idx][1] = std::max(prev[1], next[0]);
	else
		tree[idx][1] = std::max(prev[0], next[1]);
	return tree[idx];
}

lint query(int l, int r, int s, int e, int idx){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx][0] + tree[idx][1];
	int m = (l + r) >> 1;
	return std::max(query(l, m, s, e, get_left(idx)), query(m+1, r, s, e, get_right(idx)));
}

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%lld", arr+i);
	init(0, n-1, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		for(int idx = 0; idx < 4*n; idx ++){
			printf("[%d[%lld][%lld]]", idx, tree[idx][0], tree[idx][1]);
		}
		printf("\n");
		int oper, x, y;
		scanf("%d %d %d", &oper, &x, &y);
		switch(oper){
			case 1:
				update(0, n-1, x-1, y, 0);
				break;
			case 2:
				printf("%lld\n", query(0, n-1, x-1, y-1, 0));
				break;
		}
	}


	return 0;
}


