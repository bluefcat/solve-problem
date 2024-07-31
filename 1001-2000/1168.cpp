#include <cstdio>

constexpr int N = 100002;

constexpr int get_left(int x){
	return (x << 1) + 1;
}

constexpr int get_right(int x){
	return (x << 1) + 2;
}

int init(int* tree, int* arr, int l, int r, int idx){
	if(l == r) return tree[idx] = arr[l];
	int m = (l + r) >> 1;
	return tree[idx] = init(tree, arr, l, m, get_left(idx)) +
					   init(tree, arr, m+1, r, get_right(idx));
}

int sum(int* tree, int l, int r, int s, int e, int idx){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx];

	int m = (l + r) >> 1;
	return sum(tree, l, m, s, e, get_left(idx)) + sum(tree, m+1, r, s, e, get_right(idx));
}

int query(int* tree, int n, int l, int r, int k){
	int s = sum(tree, 1, n, l, r, 0);
	if(s < k) return query(tree, n, 1, n, k - s);
	if(l == r) if(k == 1) return l;

	int m = (l + r) >> 1;
	int ls = sum(tree, 1, n, l, m, 0);
	if(k <= ls) return query(tree, n, l, m, k);
	return query(tree, n, m+1, r, k-ls);
}

int update(int* tree, int l, int r, int k, int idx){
	if(!(l <= k && k <= r)) return tree[idx];
	if(l == r) return tree[idx] = 0;
	int m = (l + r) >> 1;
	return tree[idx] = update(tree, l, m, k, get_left(idx)) +
					   update(tree, m+1, r, k, get_right(idx));
}

int main(){
	int tree[4*N+4] = { 0, };
	int arr[N] = { 0, };
	int n, k, p = 1;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++)
		arr[i] = 1;
	
	init(tree, arr, 1, n, 0);
	printf("<");
	for(int i = 0; i < n; i ++){
		int x = query(tree, n, p, n, k);
		printf("%d", x);
		if(i != n-1) printf(", ");
		p = x;
		update(tree, 1, n, x, 0);
	}
	printf(">\n");

	return 0;
}
