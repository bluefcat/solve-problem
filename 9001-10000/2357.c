#include <stdio.h>
#include <limits.h>
#define N 100001
#define LEFT(X) (((X) << 1) + 1)
#define RIGHT(X) (((X) << 1) + 2)

int arr[N];

typedef struct _Result{
	int min_result;
	int max_result;
} Result;

Result tree[3*N+1];

static inline int my_max(int x, int y){
	return ((x) > (y)? (x): (y));
}

static inline int my_min(int x, int y){
	return ((x) < (y)? (x): (y));
}

Result* init(int sidx, int eidx, int idx){
	if(sidx == eidx){
		tree[idx].max_result = arr[sidx];
		tree[idx].min_result = arr[sidx];
		return tree + idx;
	} 
	int midx = (sidx + eidx) >> 1;	
	Result* left = init(sidx, midx, LEFT(idx));
	Result* right = init(midx+1, eidx, RIGHT(idx));
	
	tree[idx].max_result = my_max(
			left->max_result,
			right->max_result
			);

	tree[idx].min_result = my_min(
			left->min_result,
			right->min_result
			);
	
	return tree + idx;
}

Result query(int sidx, int eidx, int left, int right, int idx){
	if(right < sidx || eidx < left){
		Result result;
		result.max_result = INT_MIN;
		result.min_result = INT_MAX;
		return result;
	}

	if(left <= sidx && eidx <= right) return tree[idx];
	
	int midx = (sidx + eidx) >> 1;

	Result l = query(sidx, midx, left, right, LEFT(idx));
	Result r = query(midx + 1, eidx, left, right, RIGHT(idx));
	
	Result result;
	result.max_result = my_max(l.max_result, r.max_result);
	result.min_result = my_min(l.min_result, r.min_result);
	return result;
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		scanf("%d", arr + i);
	}
	
	init(0, n-1, 0);

	for(int t = 0; t < m; t ++){
		int a, b;
		scanf("%d %d", &a, &b);
		Result result = query(0, n-1, a-1, b-1, 0);
		printf("%d %d\n", result.min_result, result.max_result);
	}

	return 0;
}
