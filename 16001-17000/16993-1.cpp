#include <cstdio>
#include <algorithm>
#include <climits>

constexpr int N = 4*100000+4;
constexpr int left(int x){
	return (x << 1) + 1;
}
constexpr int right(int x){
	return (x << 1) + 2;
}

struct Node{
	int l, n, r;
};

int arr[N];
Node tree[N];

Node* init(int l, int r, int idx){
	if(l == r){
		tree[idx] = {
			0, arr[l], 0
		};
		return tree + idx;
	}

	int m = (l + r) >> 1;
	Node* lp = init(l, m, left(idx));
	Node* rp = init(m+1, r, right(idx));

	int mid = lp->n + lp->r + rp->l + rp->n;

	if(mid >= lp->n && mid >= rp->n){
		tree[idx] = {
			lp->l, mid, rp->r
		};
	}

	else if(lp->n > rp->n){
		tree[idx] = {
			lp->l, 
			lp->n, 
			lp->r + (rp->l + rp->n + rp->r)
		};
	}
	else{
		tree[idx] = {
			(lp->l + lp->n + lp->r) + rp->l,
			rp->n,
			rp->r
		};
	}


	return tree + idx;
}

Node query(int l, int r, int s, int e, int idx){
	if(r < s || e < l) return {0, INT_MIN, 0};
	if(s <= l && r <= e) return tree[idx];	
	int m = (l + r) >> 1;
	Node lp = query(l, m, s, e, left(idx));
	Node rp = query(m+1, r, s, e, right(idx));
	
	if(lp.n == INT_MIN) return {rp.l, rp.n, rp.r};
	if(rp.n == INT_MIN) return {lp.l, lp.n, lp.r};


	int mid = lp.n + lp.r + rp.l + rp.n;
	
	if(mid >= lp.n && mid >= rp.n){
		return {
			lp.l, mid, rp.r
		};
	}

	else if(lp.n > rp.n){
		return {
			lp.l, 
			lp.n, 
			lp.r + (rp.l + rp.n + rp.r)
		};
	}
	else{
		return {
			(lp.l + lp.n + lp.r) + rp.l,
			rp.n,
			rp.r
		};
	}

}


int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", arr+i);

	init(0, n-1, 0);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", query(0, n-1, s-1, e-1, 0).n);
	}

	return 0;
}
