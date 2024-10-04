#include <cstdio>
#include <utility>
#include <cassert>
using lint = long long;

constexpr int LN = 17;
constexpr int N = 100001;

lint arr[N];
lint tree[(1<<(LN+1))];

void init(int n, int size){
	for(int i = 0; i < n; i ++)
		tree[i+(size>>1)] = arr[i];
	
	for(int idx = (size>>1)-1; idx > 0; idx --)
		tree[idx] = tree[idx<<1] + tree[idx<<1|1];
}

void update(int size, int k, int diff){
	int idx = (size>>1) + k;
	tree[idx] += diff;

	while(idx>>1 != 0){
		tree[idx>>1] = tree[idx] + tree[idx^1];
		idx >>= 1;
	}
}

lint query(int size, int l, int r){
    lint result = 0;
	int lidx = (size>>1) + l, ridx = (size>>1) + r;
	while(lidx <= ridx){
		if(lidx&1) 
			result += tree[lidx++];
		if(!(ridx&1)) result += tree[ridx--];
		lidx >>= 1;
		ridx >>= 1;
	}
    return result;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);
	int size = 1;
	while(size < (n<<1)) size <<= 1;
	init(n, size);

	for(int i = 0 ; i < q; i ++){
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x > y) std::swap(x, y);
		printf("%lld\n", query(size, x-1, y-1));
		update(size, a-1, b-arr[a-1]); 
		arr[a-1] = b;
	}

	return 0;
}
