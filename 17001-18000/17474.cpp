#include <cstdio>
#include <algorithm>

using ll = long long;
constexpr int N = 10000001;
constexpr int left(int idx){ return (idx << 1) + 1; }
constexpr int right(int idx){ return (idx << 1) + 2; }

struct node{
	ll max, cnt, smax, sum;
};

node tree[4*N+4];
ll arr[N] = { 0, };

node combine(node& l, node& r){
	ll smax = 0;
	if(l.max == r.max) smax = std::max(l.smax, r.smax);
	if(l.max < r.max) smax = std::max(r.smax, l.max);
	else smax = std::max(l.smax, r.max);
	return {
		std::max(l.max, r.max),
		(l.max == r.max)? l.cnt+r.cnt: (l.max > r.max? l.cnt: r.cnt),
		smax, l.sum + r.sum
	};
}

node& init(int l, int r, int idx){
	if(l == r){
		return tree[idx] = {arr[l], 1, 0, arr[l]};
	}
	
	int m = (l + r) >> 1;
	node& lr = init(l, m, left(idx));
	node& rr = init(m+1, r, right(idx));
	return tree[idx] = combine(lr, rr);	
}

void propagate(int l, int r, int idx){
	if(l != r){
		for(auto next: {left(idx), right(idx)}){
			if(tree[next].max <= tree[idx].max) continue;
			tree[next].sum -= (tree[next].max - tree[idx].max) * tree[next].cnt;
		}
	}
	
}

node& update(int l, int r, int s, int e, ll k, int idx){
	propagate(l, r, idx);
	if(r < s || e < l || tree[idx].max <= k) return tree[idx];
	if(s <= l && r <= e && tree[idx].smax < k){
		tree[idx].sum -= (tree[idx].max - k) * tree[idx].cnt;
		tree[idx].max = k;
		propagate(l, r, idx);
		return tree[idx];
	}

	int m = (l + r) >> 1;
	node& lr = update(l, m, s, e, k, left(idx));
	node& rr = update(m+1, r, s, e, k, right(idx));
	
	return tree[idx] = combine(lr, rr);
}

ll query_max(int l, int r, int s, int e, int idx){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx].max;
	int m = (l + r) >> 1;
	return std::max(query_max(l, m, s, e, left(idx)), query_max(m+1, r, s, e, right(idx)));
}


ll query_sum(int l, int r, int s, int e, int idx){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx].sum;
	int m = (l + r) >> 1;
	return query_sum(l, m, s, e, left(idx)) + query_sum(m+1, r, s, e, right(idx));
}


int main(){
	int n, m;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		ll x;
		scanf("%lld", &x);
		arr[i] = x;
	}
	init(0, n-1, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper, l, r; ll x;
		scanf("%d %d %d", &oper, &l, &r);
		switch(oper){
			case 1:
			scanf("%lld", &x);
			update(0, n-1, l-1, r-1, x, 0);
			break;
			case 2:
			printf("%lld\n", query_max(0, n-1, l-1, r-1, 0));
			break;
			case 3:
			printf("%lld\n", query_sum(0, n-1, l-1, r-1, 0));
			break;
		}
	}
	


	return 0;
}
