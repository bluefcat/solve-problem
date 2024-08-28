#include <cstdio>
#include <algorithm>

using ll = long long;
constexpr int N = 100001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }

ll arr[N] = { 0, };
ll tree[4*N+4][3] = { 0, }; //[n, a0, step]

ll init(int l, int r, int idx){
	if(l == r) return tree[idx][0] = arr[l];
	int m = (l+r) >> 1;
	return tree[idx][0] = init(l, m, get_left(idx)) +
						  init(m+1, r, get_right(idx));
}

void propagate(int l, int r, int idx){
	if(tree[idx][1] == 0 || tree[idx][2] == 0) return;

	ll a = tree[idx][1];
	ll step = tree[idx][2];
	//printf("propagate(%d %d %lld %lld)\n", l, r, a, step);
	int lidx = get_left(idx), ridx = get_right(idx);

	if(l != r){
		ll m = (l + r) >> 1;
		tree[lidx][1] += a;
		tree[lidx][2] += step;
		tree[ridx][1] += a+(m-l+1)*step; // a + (n-1)*d
		tree[ridx][2] += step;
	}
	tree[idx][0] += (r-l+1)*(2*a+(r-l)*step) >> 1;
	tree[idx][1] = 0;
	tree[idx][2] = 0;
}

ll update(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] += l-s+1, tree[idx][2] += 1;
		propagate(l, r, idx);
		return tree[idx][0];
	}
	int m = (l + r) >> 1;
	return tree[idx][0] = update(l, m, s, e, get_left(idx)) +
						  update(m+1, r, s, e, get_right(idx));
}

ll query(int l, int r, int k, int idx){
	propagate(l, r, idx);
	if(!(l <= k && k <= r)) return 0;
	if(l == r) return tree[idx][0];
	
	int m = (l + r) >> 1;
	return std::max(
			query(l, m, k, get_left(idx)), 
			query(m+1, r, k, get_right(idx))
	);
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%lld", arr+i);

	init(0, n-1, 0);
	int q;
	q = 100000;
	scanf("%d", &q);
	for(int i = 0; i < q; i ++){
		int oper, x, y;
		scanf("%d", &oper);
		if(oper == 1){
			scanf("%d %d", &x, &y);
			update(0, n-1, x-1, y-1, 0);
		}
		else{
			scanf("%d", &x);
			ll q = query(0, n-1, x-1, 0);
			printf("%lld\n", q);
		}
	}

	return 0;
}
