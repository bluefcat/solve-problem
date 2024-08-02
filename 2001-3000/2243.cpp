#include <cstdio>

constexpr int N = 101; //1000001;
constexpr int get_left(int x){
	return (x << 1) + 1;
}
constexpr int get_right(int x){
	return (x << 1) + 2;
}

int query(int* tree, int l, int r, int k, int idx){
	if(l == r) return l;
	
	int lidx = get_left(idx);
	int m = (l + r) >> 1;
	if(k <= tree[lidx])
		return query(tree, l, m, k, get_left(idx));
	return query(tree, m+1, r, k-tree[lidx], get_right(idx));
}

int update(int* tree, int l, int r, int k, int diff, int idx){
	if(!(l <= k && k <= r)) return tree[idx];	
	if(l == r) return tree[idx] += diff;
	int m = (l + r) >> 1;
	int lr = update(tree, l, m, k, diff, get_left(idx));
	int rr = update(tree, m+1, r, k, diff, get_right(idx));
	return tree[idx] = lr + rr;
}


int main(){
	int tree[4*N+4] = { 0, };
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int oper, lv, c, x;
		scanf("%d", &oper);
		switch(oper){
			case 1:
				scanf("%d", &lv);
				x = query(tree, 0, N-1, lv, 0);
				printf("%d\n", x);
				update(tree, 0, N-1, x, -1, 0);
				break;
			case 2:
				scanf("%d %d", &lv, &c);
				update(tree, 0, N-1, lv, c, 0);
				break;
		}
	}
	return 0;
}
