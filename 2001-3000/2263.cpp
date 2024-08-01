#include <cstdio>
#include <array>
using std::array;

constexpr int N = 100001;

template<typename T>
void print(
	T& pos, T& post_order,
	int s, int l, int r
){
	int base = post_order[r];
	printf("%d ", base);
	if(l == r) return;	
	int idx = pos[base] - s;
	if(l <= l+idx-1)
		print(pos, post_order, s, l, l+idx-1);
	if(l+idx <= r-1)
		print(pos, post_order, s+idx+1, l+idx, r-1);
}

int main(){
	int n;
	array<int, N> position;
	array<int, N> post_order;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		int p;
		scanf("%d", &p);
		position[p] = i;
	}
	
	for(int i = 0; i < n; i ++)
		scanf("%d", post_order.begin()+i);
	
	print(position, post_order, 0, 0, n-1);
	printf("\n");
	return 0;
}
