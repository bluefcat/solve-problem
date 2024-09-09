#include <cstdio>
#include <algorithm>

using uint = unsigned int;
constexpr int N = 100001;
constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1) + 2; }

uint tree[4*N+4][2] = { 0, };

void propagate(int l, int r, int idx){
	if(tree[idx][1] == 0) return;
	if(l != r){
		tree[get_left(idx)][1] = tree[idx][1];
		tree[get_right(idx)][1] = tree[idx][1];
	}
	tree[idx][0] = tree[idx][1];
	tree[idx][1] = 0;
}

uint update(int l, int r, int s, int e, uint v, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][1] = v;
		propagate(l, r, idx);
		return tree[idx][0];
	}
	
	int m = (l + r) >> 1;
	uint lr = update(l, m, s, e, v, get_left(idx));
	uint rr = update(m+1, r, s, e, v, get_right(idx));
	
	return tree[idx][0] = lr | rr;
}

uint query(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return tree[idx][0];

	int m = (l + r) >> 1;
	return query(l, m, s, e, get_left(idx)) | query(m+1, r, s, e, get_right(idx));
}


int main(){
	for(int i = 0; i < 4*N+4; i ++) tree[i][0] = 1;
	int n, t, q;
	scanf("%d %d %d", &n, &t, &q);
	for(int i = 0; i < q; i ++){
		char oper; int x, y; uint z;
		scanf(" %c %d %d", &oper, &x, &y);
		if(x > y) std::swap(x, y);
		switch(oper){
			case 'C':
				scanf("%u", &z);
				update(0, n-1, x-1, y-1, 1<<(z-1), 0);
				break;
			case 'Q':
				z = query(0, n-1, x-1, y-1, 0);
				printf("%d\n", __builtin_popcount(z));
				break;
		}
	}
	return 0;
}
