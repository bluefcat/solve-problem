#include <cstdio>

using ll = long long;
constexpr int N = 100001;

constexpr int get_left(int x){
	return (x << 1) + 1;
}

constexpr int get_right(int x){
	return (x << 1) + 2;
}


ll init(ll tree[][2], ll* arr, int l, int r, int idx){
	if(l == r) return tree[idx][0] = arr[l];
	int m = (l+r)>>1;
	ll left_result = init(tree, arr, l, m, get_left(idx));
	ll right_result = init(tree, arr, m+1, r, get_right(idx));
	return tree[idx][0] = left_result + right_result;
}

ll query(ll tree[][2], int l, int r, int q, int idx){
	if(l == r) return tree[idx][0] + tree[idx][1];
	int m = (l+r)>>1;
	if(q <= m)
		return query(tree, l, m, q, get_left(idx)) + tree[idx][1];
	return query(tree, m+1, r, q, get_right(idx)) + tree[idx][1];
}

void update(ll tree[][2], int l, int r, int s, int e, int k, int idx){
	if(r < s || e < l) return;
	if(l == r) {
		tree[idx][1] += k;	
		return;
	}
	if(l <= s && e <= r){
		tree[idx][1] += k;
		return;
	}
	
	int m = (l+r) >> 1;
	update(tree, l, m, s, e, k, get_left(idx));
	update(tree, m+1, r, s, e, k, get_right(idx));
	return;
}

int main(){
	ll tree[4*N+4][2] = { 0, };
	ll arr[N] = { 0, };

	int n = 0, m = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	init(tree, arr, 0, n-1, 0);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper; scanf("%d", &oper);
		switch(oper){
			case 1:{
				int p, q, r;
				scanf("%d %d %d", &p, &q, &r);
				update(tree, 0, n-1, p-1, q-1, r, 0);
				   }
				break;
			case 2:{
				int x;
				scanf("%d", &x);
				ll result = query(tree, 0, n-1, x-1, 0);
				printf("%lld\n", result);
				   }
				break;
		}
	}

}
