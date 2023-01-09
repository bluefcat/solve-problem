#include <stdio.h>
#include <limits.h>

int n, m;
int arr[100002];
int max_tree[100003];
int min_tree[100003];

static inline int my_max(int x, int y){
	return ((x) > (y)? (x): (y));
}

static inline int my_min(int x, int y){
	return ((x) < (y)? (x): (y));
}

int max_init(int start, int end, int node){
	if(start == end) return max_tree[node] = arr[start];
	int mid = (start + end) >> 1;
	return max_tree[node] = my_max(max_init(start, mid, node << 1), max_init(mid+1, end, (node << 1) + 1));
}

int min_init(int start, int end, int node){
	if(start == end) return min_tree[node] = arr[start];
	int mid = (start + end) >> 1;
	return min_tree[node] = my_min(min_init(start, mid, node << 1), min_init(mid+1, end, (node << 1) + 1));
}

int max_find(int start, int end, int node, int left, int right){
	if(end < left || right < start) return INT_MIN;

	int mid = (start + end) >> 1;

	return my_max(max_find(start, mid, node << 1, left, right),
				  max_find(mid+1, end, (node << 1) + 1, left, right));
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		scanf("%d", arr + i);
	}

	max_init(0, n-1, 1);
	min_init(0, n-1, 1);

	for(int t = 0; t < m; t ++){
		int a, b;
		scanf("%d %d", &a, &b);
		int mx = max_find(0, n-1, 1, a, b);

		printf("[%d]\n", mx);
	}

	return 0;
}
