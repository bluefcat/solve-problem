#include <stdio.h>
#include <limits.h>

int n, m;
int arr[100002];
int max_arr[100003];
int min_arr[100003];

struct result{
	int min;
	int max;
};

static inline int max(int x, int y){
	return ((x) > (y)? (x): (y));
}

static inline int min(int x, int y){
	return ((x) < (y)? (x): (y));
}

void init(int start, int end, int node){
	if(start == end){
		min_arr[node] = arr[node];
		max_arr[node] = arr[node];
		return;
	}

	int mid = (start + end) >> 1;
	init(start, mid, node << 1);
	init(mid+1, end, (node << 1) + 1);

	min_arr[node] = min(min_arr[node << 1], min_arr[(node << 1) + 1]);
	max_arr[node] = max(max_arr[node << 1], max_arr[(node << 1) + 1]);

	return;
}

void find(int start, int end, int node, int left, int right, struct result* r){
	if(left > end || right < start){
		r->min = INT_MAX;
		r->max = INT_MIN;
		return;
	}
	struct result a, b;

	int mid = (left + right) >> 1;

	find(start, end, node << 1, left, mid, &a);
	find(start, end, (node << 1)+1, mid+1, right, &b);

	
	r->min = min(a.min, b.min);
	r->max = max(a.max, b.max);

	return;
}


int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		scanf("%d", arr + i);
	}

	init(0, n-1, 1);

	for(int t = 0; t < m; t ++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		struct result r;
		find(0, n-1, 1, a-1, b-1, &r);
		
		printf("%d %d\n", r.min, r.max);
	}

	return 0;
}
