#include <cstdio>
#include <algorithm>

constexpr int N = 100008;
constexpr int LN = 18;

int arr[N] = { 0, };
int sorted[N] = { 0, };
int tree[LN][N] = { 0, };

int result[N] = { 0, };

void method(int l, int m, int r, int h){
	int p = l, q = m+1;
	int idx = 0;
	while(p <= m && q <= r){
		if(tree[h+1][p] <= tree[h+1][q])
			sorted[idx++] = tree[h+1][p++];
		else
			sorted[idx++] = tree[h+1][q++];
	}
	while(q <= r)
		sorted[idx++] = tree[h+1][q++];
	while(p <= m)
		sorted[idx++] = tree[h+1][p++];
}

void init(int l, int r, int h){
	if(l == r){
		tree[h][l] = arr[l];
		return;
	}
	
	int m = (l + r) >> 1;
	init(l, m, h+1);
	init(m+1, r, h+1);
	method(l, m, r, h);
	for(int i = 0; i < r-l+1; i++)
		tree[h][l+i] = sorted[i];
	return;
}

std::pair<int, int> query(int l, int r, int s, int e, int h){
	if(r < s || e < l) return {-1, -2};	
	if(s <= l && r <= e){
		for(int i = l; i <= r; i ++) result[i] = tree[h][i];
		return {l, r};
	}
	
	int m = (l + r) >> 1;

	auto [ll, lr] = query(l, m, s, e, h+1);
	auto [rl, rr] = query(m+1, r, s, e, h+1);


	int p = ll, q = rl, idx = 0;
	while(p <= lr && q <= rr){
		if(result[p] <= result[q])
			sorted[idx++] = result[p++];
		else
			sorted[idx++] = result[q++];
	}
	while(q <= rr)
		sorted[idx++] = result[q++];
	while(p <= lr)
		sorted[idx++] = result[p++];

	int pivot = (ll >= 0)? ll: rl;
	int end = (rr >= 0)? rr: lr;
	for(int i = 0; i < idx; i ++)
		result[i+pivot] = sorted[i];
	return {pivot, end};
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);	
	for(int i = 0; i < n; i ++){
		scanf("%d", arr+i);
	}

	init(0, n-1, 0);
	for(int q = 0; q < m; q ++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		query(0, n-1, i-1, j-1, 0);
		printf("%d\n", result[i+k-2]);
	}

	return 0;
}
