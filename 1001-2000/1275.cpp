#include <cstdio>
#define N 100001

using ll = long long;

ll arr[N];
ll tree[4*N];

static inline int get_left(int x){return (((x) << 1) + 1);}
static inline int get_right(int x){return (((x) << 1) + 2);}

ll init(int sidx, int eidx, int idx){
	if(sidx == eidx) return tree[idx] = arr[sidx];

	int midx = (sidx + eidx) >> 1;
	ll l = init(sidx, midx, get_left(idx));
	ll r = init(midx+1, eidx, get_right(idx));
	return tree[idx] = l + r;
}

ll sum(int sidx, int eidx, int le, int ri, int idx){
	if(ri < sidx || eidx < le) return 0;
	if(le <= sidx && eidx <= ri) return tree[idx];
	
	int midx = (sidx + eidx) >> 1;
	ll l = sum(sidx, midx, le, ri, get_left(idx));
	ll r = sum(midx+1, eidx, le, ri, get_right(idx));
	return l + r;
}

ll update(int sidx, int eidx, int x, int n, int idx){
	if(!(sidx <= x && x <= eidx)) return tree[idx];
	if(sidx == eidx){ //sidx = x
		return tree[idx] = n;
	}

	int midx = (sidx + eidx) >> 1;
	ll l = update(sidx, midx, x, n, get_left(idx));
	ll r = update(midx+1, eidx, x, n, get_right(idx));
	return tree[idx] = l + r;
}


int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i < n; i ++) scanf("%lld", arr + i);
	init(0, n-1, 0);

	for(int i = 0; i < q; i ++){
		int x, y, a; 
		ll b;
		scanf("%d %d %d %lld", &x, &y, &a, &b);

		if(y < x){
			int tmp = x; x = y; y = tmp;
		}

		ll result = sum(0, n-1, x-1, y-1, 0);
		printf("%lld\n", result);
		update(0, n-1, a-1, b, 0);
	}

	return 0;
}
