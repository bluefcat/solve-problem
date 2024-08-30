#include <cstdio>
#include <algorithm>

constexpr int N = 100001;
constexpr int LN = 17;

int arr[N] = { 0, };
int sorted[N] = { 0, };
int tree[LN][N] = { 0, };

void init(int l, int r, int h){
	if(l == r){
		tree[h][l] = arr[l];
		return;
	}
	
	int m = (l + r) >> 1;
	init(l, m, h+1);
	init(m+1, r, h+1);

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
	for(int i = 0; i < idx; i++)
		tree[h][l+i] = sorted[i];
	return;
}

int query(int l, int r, int s, int e, int k, int h){
	if(r < s || e < l) return 0;	
	if(s <= l && r <= e){
		int idx = std::upper_bound(tree[h]+l, tree[h]+r+1, k) - (tree[h]+l);
		return (r-l+1)-idx;
	}
	
	int m = (l + r) >> 1;
	return query(l, m, s, e, k, h+1) + query(m+1, r, s, e, k, h+1);
}

int main(){
	int n;
	scanf("%d", &n);	
	for(int i = 0; i < n; i ++){
		scanf("%d", arr+i);
	}

	init(0, n-1, 0);
	int m;
	scanf("%d", &m);
	for(int q = 0; q < m; q ++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", query(0, n-1, i-1, j-1, k, 0));
	}

	return 0;
}
