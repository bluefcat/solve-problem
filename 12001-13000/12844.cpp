#include <cstdio>

constexpr int N = 50001; //500001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }

int init(int arr[], int tree[][2], int l, int r, int idx){
	if(l == r) return tree[idx][0] = arr[l];
	int m = (l + r) >> 1;
	int lr = init(arr, tree, l, m, get_left(idx));
	int rr = init(arr, tree, m+1, r, get_right(idx));
	return tree[idx][0] = lr^rr;
}

void propagate(int tree[][2], int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] ^= tree[idx][1];
		tree[get_right(idx)][1] ^= tree[idx][1];
	}
	if((r-l+1)&1)
		tree[idx][0] ^= tree[idx][1];
	tree[idx][1] = 0;
}


int update(int tree[][2], int l, int r, int s, int e, int k, int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] = k;
		propagate(tree, l, r, idx);
		return tree[idx][0];
	}
	int m = (l+r) >> 1;
	return tree[idx][0] = update(tree, l, m, s, e, k, get_left(idx)) ^
						  update(tree, m+1, r, s, e, k, get_right(idx));
}

int query(int tree[][2], int l, int r, int s, int e, int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx][0];
	int m = (l + r ) >> 1;
	return query(tree, l, m, s, e, get_left(idx)) ^ 
		   query(tree, m+1, r, s, e, get_right(idx));
}

int main(){
	int arr[N] = { 0, };
	int tree[4*N+4][2] = { 0, };
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	init(arr, tree, 0, n-1, 0);

	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper, s, t, k;
		scanf("%d", &oper);
		if(oper == 1){
			scanf("%d %d %d", &s, &t, &k);
			update(tree, 0, n-1, s, t, k, 0);
		}

		else{
			scanf("%d %d", &s, &t);
			int q = query(tree, 0, n-1, s, t, 0);
			printf("%d\n", q);
		}
	}
}



