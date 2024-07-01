#include <cstdio>
#include <algorithm>
#define N 100001
using ll = long long;

ll arr[N];

ll get_max(int sidx, int eidx){
	if(sidx == eidx) return arr[sidx];

	int midx = (sidx + eidx) >> 1;
	
	ll l = get_max(sidx, midx);
	ll r = get_max(midx+1, eidx);
	
	ll m = 0;	
	ll h = arr[midx];
	
	int s = midx; int e = midx;

	while(sidx < s || e < eidx){
		m = std::max({m, h*(e-s+1)});
		
		if(sidx < s && e < eidx){
			if(sidx < s && arr[s-1] >= arr[e+1]) s--;
			else if(e < eidx && arr[s-1] < arr[e+1]) e++;
		}
		else{
			if(sidx < s) s --;
			if(e < eidx) e ++;
		}
		h = std::min({arr[s], arr[e], h});
	}
	h = std::min({arr[s], arr[e], h});
	m = std::max({m, h*(e-s+1)});
	return std::max({l, r, m});
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%lld", arr+i);
	ll result = get_max(0, n-1);
	printf("%lld\n", result);

	return 0;
}
