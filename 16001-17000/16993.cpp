#include <cstdio>
#include <algorithm>
#include <climits>

constexpr int N = 100001;
constexpr int get_left(int x){return (x << 1) + 1;}
constexpr int get_right(int x){return (x << 1) + 2;}

struct Node{
	int n, sum, l, r;
};

Node& init(int arr[N], Node tree[N], int l, int r, int idx){
	if(l == r){
		tree[idx] = {arr[l], arr[l], l, r};
		return tree[idx];
	}
	
	int m = (l + r) >> 1;
	Node& ln = init(arr, tree, l, m, get_left(idx));
	Node& rn = init(arr, tree, m+1, r, get_right(idx));

	int sum = ln.sum+rn.sum;
	int mid = INT_MIN;

	if(ln.r + 1 == rn.l) mid = ln.n + rn.n;
	if(mid >= std::max(ln.n, rn.n) || sum >= std::max(ln.n, rn.n))
		tree[idx] = {std::max(mid, sum), sum, ln.l, rn.r};
	else{
		if(ln.n > rn.n)
			tree[idx] = {ln.n, sum, ln.l, ln.r};
		else
			tree[idx] = {rn.n, sum, rn.l, rn.r};
	}
	return tree[idx];
}

Node query(Node tree[N], int l, int r, int s, int e, int idx){
	if(r < s || e < l) return Node{INT_MIN, 0, -1, -1};
	if(s <= l && r <= e) return tree[idx];

	int m = (l + r) >> 1;
	Node result{};
	Node ln = query(tree, l, m, s, e, get_left(idx));
	Node rn = query(tree, m+1, r, s, e, get_right(idx));

	int sum = ln.sum+rn.sum;
	int mid = INT_MIN;
	
	if(ln.l != -1 && rn.r != -1){
		if(ln.r + 1 == rn.l) mid = ln.n + rn.n;
		if(mid >= std::max(ln.n, rn.n) || sum >= std::max(ln.n, rn.n))
			return {std::max(mid, sum), sum, ln.l, rn.r};
	}
	
	if(ln.n > rn.n)
		result = {ln.n, sum, ln.l, ln.r};
	else
		result = {rn.n, sum, rn.l, rn.r};
	
	return result;

}

int main(){
	int arr[N] = { 0, };
	Node tree[4*N+4] = { 0, };
	
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", arr+i);
	init(arr, tree, 0, n-1, 0);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", query(tree, 0, n-1, s-1, e-1, 0).n);
	}

	return 0;
}
