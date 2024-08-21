#include <cstdio>

constexpr int N = 100001;
constexpr int get_left(int x){ return (x << 1) + 1; }
constexpr int get_right(int x){ return (x << 1) + 2; }

void propagate(int tree[][2], int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] ^= tree[idx][1];
		tree[get_right(idx)][1] ^= tree[idx][1];
	}
	tree[idx][0] = (r-l+1) - tree[idx][0];
	tree[idx][1] = 0;
}


int update(int tree[][2], int l, int r, int s, int e, int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] = 1;
		propagate(tree, l, r, idx);
		return tree[idx][0];
	}
	int m = (l+r) >> 1;
	return tree[idx][0] = update(tree, l, m, s, e, get_left(idx)) +
						  update(tree, m+1, r, s, e, get_right(idx));
}

int query(int tree[][2], int l, int r, int s, int e , int idx){
	propagate(tree, l, r, idx);
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx][0];
	int m = (l + r ) >> 1;
	return query(tree, l, m, s, e, get_left(idx)) + 
		   query(tree, m+1, r, s, e, get_right(idx));
}

int main(){
	int tree[4*N+4][2] = { 0, };
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int oper, s, t;
		scanf("%d %d %d", &oper, &s, &t);
		if(oper == 0) update(tree, 0, n-1, s-1, t-1, 0);
		else{
			int q = query(tree, 0, n-1, s-1, t-1, 0);
			printf("%d\n", q);
		}
	}
}



