#include <cstdio>
#include <utility>
using lint = long long;

constexpr int LN = 17;
constexpr int N = 100001;
constexpr int get_parent(int idx){ return (idx - 1) >> 1;}
constexpr int get_left(int idx){ return (idx << 1) + 1;}
constexpr int get_right(int idx){ return (idx << 1) + 2;}

lint arr[N];
lint tree[(1<<(LN+1))-1];

void init(int size){
	for(int i = (size >> 1), idx = 0; i < size; i ++, idx ++)
		tree[i] = arr[idx];
	
	for(int idx = (size >> 1)-1; idx >= 0; idx --)
		tree[idx] = tree[get_left(idx)] + tree[get_right(idx)];
}

void update(int size, int k, int v){
	int idx = (size>>1) + k;
	tree[idx] += v;

	while(idx > 0){
		idx = get_parent(idx);
		tree[idx] += v;
	}
}

lint query(int size, int l, int r){
    lint result = 0;
	int lidx = (size>>1) + l, ridx = (size>>1) + r;
	while(lidx <= ridx){
		if(!(lidx&1)) 
			result += tree[lidx++];
		if(ridx&1) result += tree[ridx--];
		lidx = get_parent(lidx);
		ridx = get_parent(ridx);
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
	init(size);

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
