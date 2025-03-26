#include <cstdio>

using ll = long long;
constexpr int N = 500001;
constexpr int get_left(int x){ return (x << 1) + 1;}
constexpr int get_right(int x){ return (x << 1) + 2; }

ll query(ll* tree, int l, int r, int k, int idx){
	if(k <= l) return 0;
	if(r < k) return tree[idx];
	int m = (l+r) >> 1;
	return query(tree, l, m, k, get_left(idx)) + 
		   query(tree, m+1, r, k, get_right(idx));
}

ll update(ll* tree, int l, int r, int k, int idx){
	if(!(l <= k && k <= r)) return tree[idx];
	if(l == r) return tree[idx] = tree[idx]+1;
	int m = (l+r) >> 1;
	return tree[idx] = update(tree, l, m, k, get_left(idx)) + 
					   update(tree, m+1, r, k, get_right(idx));
}

int main(){
	int dict[N] = { 0, };
	int arr[N] = { 0, };
	ll tree[4*N+4] = { 0, };
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		dict[x] = i;
	}
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		arr[i] = dict[x];
	}
	ll result = 0;

	for(ll i = 0; i < n; i ++){
		ll x = query(tree, 0, n-1, arr[i], 0);
		result += i-x;
		update(tree, 0, n-1, arr[i], 0);
	}
	printf("%lld\n", result);
	return 0;
}
