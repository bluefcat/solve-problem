#include <cstdio>

constexpr int N = 16;//20002; //2000002
constexpr int get_left(int x){
	return (x<<1)+1;
}

constexpr int get_right(int x){
	return (x<<1)+2;
}

int query(int* tree, int l, int r, int k, int idx){
	if(l == r) return l;
	int m = (l + r) >> 1;
	if(k <= tree[get_left(idx)])
		return query(tree, l, m, k, get_left(idx));
	else
		return query(tree, m+1, r, k - tree[get_left(idx)], get_right(idx));
}

int update(int* tree, int l, int r, int k, int d, int idx){
	if(!(l <= k && k <= r)) return tree[idx];	
	if(l == r) return tree[idx] += d;

	int m = (l + r) >> 1;
	int left_result = update(tree, l, m, k, d, get_left(idx));
	int right_result = update(tree, m+1, r, k, d, get_right(idx));
	return tree[idx] = left_result + right_result;}


int main(){
	int tree[4*N+4] = { 0, };
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int oper, x, result = 0;
		scanf("%d %d", &oper, &x);
		switch(oper){
			case 1:
				update(tree, 0, N-1, x, 1, 0);
				break;
			case 2:
				result = query(tree, 0, N-1, x, 0);
				update(tree, 0, N-1, result, -1, 0);
				printf("%d\n", result);
				break;
		}
	}

	return 0;
}
