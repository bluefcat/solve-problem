#include <cstdio>

using ll = long long;

constexpr int N = 100001;
constexpr int M = 1000000000+7;

constexpr int get_left(int idx){ return (idx << 1) + 1; }
constexpr int get_right(int idx){ return (idx << 1) + 2; }

ll arr[N] = { 0, };
ll tree[4*N+4][4] = { 0, };

void propagate(int l, int r, int idx){
	if(tree[idx][1] == 1 && tree[idx][2] == 0)
		return;
	if(l != r){
		tree[get_left(idx)][1] = (tree[get_left(idx)][1]*tree[idx][1]) % M;
		tree[get_right(idx)][1] = (tree[get_right(idx)][1]*tree[idx][1]) % M;
		tree[get_left(idx)][2] = (tree[idx][2]+(tree[idx][1]*tree[get_left(idx)][2])%M) % M;
		tree[get_right(idx)][2] = (tree[idx][2]+(tree[idx][1]*tree[get_right(idx)][2])%M) % M;
	}

	tree[idx][0] = ((tree[idx][1] * tree[idx][0])%M + ((r-l+1)*tree[idx][2])%M) % M;

	tree[idx][1] = 1;
	tree[idx][2] = 0;
}

ll init(int l, int r, int idx){
	if(l == r){ 
		tree[idx][1] = 1;
		return tree[idx][0] = arr[l];
	}
	int m = (l + r) >> 1;
	tree[idx][1] = 1;
	return tree[idx][0] = (init(l, m, get_left(idx)) + init(m+1, r, get_right(idx)))%M;
}

ll update(int l, int r, int s, int e, int oper, int v, int idx){
	propagate(l, r, idx);
	if(e < l || r < s) return tree[idx][0];
	if(s <= l && r <= e){
		tree[idx][3] = oper;
		switch(oper){
			case 1:
			tree[idx][2] += v;
			break;
			case 2:
			tree[idx][1] *= v; tree[idx][2] *= v; 	
			break;
			case 3:
			tree[idx][1] = 0; tree[idx][2] = v;
			break;
		}
		propagate(l, r, idx);
		return tree[idx][0];
	}
	
	int m = (l + r) >> 1;
	ll lr = update(l, m, s, e, oper, v, get_left(idx));
	ll ll = update(m+1, r, s, e, oper, v, get_right(idx));
	return tree[idx][0] = (lr + ll) % M;
}

ll query(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(e < l || r < s) return 0;
	if(s <= l && r <= e) return tree[idx][0];

	int m = (l + r) >> 1;
	ll lr = query(l, m, s, e, get_left(idx));
	ll rr = query(m+1, r, s, e, get_right(idx));

	return (lr + rr) % M;
}



int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);
	init(0, n-1, 0);
	scanf("%d", &m);

	for(int i = 0; i < m; i ++){
		int oper, x, y, v;
		scanf("%d %d %d", &oper, &x, &y);
		if(oper != 4){
			scanf("%d", &v);
			update(0, n-1, x-1, y-1, oper, v, 0);
		}
		else{
			printf("%lld\n", query(0, n-1, x-1, y-1, 0));
		}
	}


	return 0;
}
