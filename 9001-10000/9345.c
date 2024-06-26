#include <stdio.h>
#include <limits.h>

#define N 100001

static inline int left(int x){return (((x) << 1) + 1);}
static inline int right(int x){return (((x) << 1) + 2);}
static inline int my_max(int x, int y){return ((x) > (y)? (x): (y));}
static inline int my_min(int x, int y){return ((x) < (y)? (x): (y));}

typedef struct _Result{
	int min_result;
	int max_result;
} Result;

Result* init(
	Result* tree, int* arr, int sidx, int eidx, int idx
){
	if(sidx == eidx){
		tree[idx].max_result = arr[sidx];
		tree[idx].min_result = arr[sidx];
		return tree + idx;
	} 
	int midx = (sidx + eidx) >> 1;	
	Result* l = init(tree, arr, sidx, midx, left(idx));
	Result* r = init(tree, arr, midx+1, eidx, right(idx));
	
	tree[idx].max_result = my_max(
			l->max_result,
			r->max_result
			);

	tree[idx].min_result = my_min(
			l->min_result,
			r->min_result
			);
	
	return tree + idx;
}

Result query(
	Result* tree, int sidx, int eidx, int le, int ri, int idx
){
	if(ri < sidx || eidx < le){
		Result result;
		result.max_result = INT_MIN;
		result.min_result = INT_MAX;
		return result;
	}

	if(le <= sidx && eidx <= ri) return tree[idx];
	
	int midx = (sidx + eidx) >> 1;

	Result l = query(tree, sidx, midx, le, ri, left(idx));
	Result r = query(tree, midx + 1, eidx, le, ri, right(idx));
	
	Result result;
	result.max_result = my_max(l.max_result, r.max_result);
	result.min_result = my_min(l.min_result, r.min_result);
	return result;
}

Result* update(
	Result* tree,
	int sidx, int eidx, int x, int y, int idx
){
	if(!((sidx <= x && x <= eidx))){
		return tree+idx;
	};
	
	if(sidx == eidx && sidx == x){ 
		tree[idx].max_result = y;
		tree[idx].min_result = y;
		return tree+idx;
	}
	int midx = (sidx + eidx) >> 1;	
	Result* l = update(tree, sidx, midx, x, y, left(idx));
	Result* r = update(tree, midx+1, eidx, x, y, right(idx));

	tree[idx].max_result = my_max(
		l->max_result, r->max_result
	);

	tree[idx].min_result = my_min(
		l->min_result, r->min_result
	);

	return tree+idx;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int video[N] = { 0, };
		for(int i = 0; i < N; i ++) video[i] = i;
		Result tree[3*N+1];
		int n, k;
		scanf("%d %d", &n, &k);	
		init(tree, video, 0, n-1, 0);
		while(k--){
			int q, a, b, tmp;
			Result result;
			scanf("%d %d %d", &q, &a, &b);
			int l, r;
			switch(q){
				case 0:
					update(tree, 0, n-1, a, video[b], 0);
					update(tree, 0, n-1, b, video[a], 0);
					tmp = video[a];
					video[a] = video[b];
					video[b] = tmp;
					break;
				case 1:
					result = query(tree, 0, n-1, a, b, 0);
					tmp = (result.min_result == a) && (result.max_result == b);
					printf("%s\n", tmp?"YES":"NO");
					break;
			}
		}
	}

	return 0;
}
