#include <cstdio>
using ll = long long;
constexpr int N = 1000001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }


ll init(ll arr[], ll tree[][2], int l, int r, int idx){
	if(l == r) return tree[idx][0] = arr[l];
	int m = (l + r) >> 1;
	return tree[idx][0] = init(arr, tree, l, m, get_left(idx)) +
						  init(arr, tree, m+1, r, get_right(idx));
}

void propagate(ll tree[][2], int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] += tree[idx][1];
	 	tree[get_right(idx)][1] += tree[idx][1];
	}
	tree[idx][0] += tree[idx][1] * (r-l+1);
	tree[idx][1] = 0;
}

ll update(ll tree[][2], int l, int r, int s, int e, ll k, int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] += k;
		propagate(tree, l, r, idx);
		return tree[idx][0];
	}

	int m = (l + r) >> 1;
	ll lr = update(tree, l, m, s, e, k, get_left(idx));
	ll rr = update(tree, m+1, r, s, e, k, get_right(idx));
	return tree[idx][0] = lr + rr;
}

ll query(ll tree[][2], int l, int r, int s, int e, int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx][0];
	int m = (l + r) >> 1;
	return query(tree, l, m, s, e, get_left(idx)) +
		   query(tree, m+1, r, s, e, get_right(idx));
}

int main(){
	ll arr[N] = { 0, };
	ll tree[4*N+4][2] = { 0, }; //[1] is lazy cache

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i ++) scanf("%lld", arr+i);
	init(arr, tree, 0, n-1, 0);

	for(int i = 0; i < m+k; i ++){
		int oper, x, y;
		ll z, q;
		scanf("%d", &oper);
		switch(oper){
			case 1:
				scanf("%d %d %lld", &x, &y, &z);
				update(tree, 0, n-1, x-1, y-1, z, 0);
			break;

			case 2:
				scanf("%d %d", &x, &y);	
				q = query(tree, 0, n-1, x-1, y-1, 0);
				printf("%lld\n", q);
			break;
		}	

	}

	return 0;
}
