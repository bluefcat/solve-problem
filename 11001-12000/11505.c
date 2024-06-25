#include <stdio.h>

#define LEFT(X) (((X)<<1)+1)
#define RIGHT(X) (((X)<<1)+2)
#define MOD 1000000007
#define N 1000001
#define ll long long

ll arr[N];
ll tree[3*N+1];

ll pow_mod(ll base, ll x){
	ll result = 1;
	for(;x; x >>= 1, base = (base*base) % MOD){
		if(x&1) result = (result*base) % MOD;
	}
	return result;
}

ll init(ll sidx, ll eidx, ll idx){
	if(sidx == eidx) return tree[idx] = arr[sidx];
	ll midx = (sidx+eidx) >> 1;
	return tree[idx] = 
		(init(sidx, midx, LEFT(idx)) *
		init(midx+1, eidx, RIGHT(idx))) % MOD;
}

ll product(ll sidx, ll eidx, ll left, ll right, ll idx){
	if(right < sidx || eidx < left) return 1;
	if(left <= sidx && eidx <= right) return tree[idx];	
	ll midx = (sidx+eidx) >> 1;
	return (product(sidx, midx, left, right, LEFT(idx)) *
		    product(midx+1, eidx, left, right, RIGHT(idx))) % MOD;
}

ll update(ll sidx, ll eidx, ll p, ll n, ll idx){
	if(!(sidx <= p && p <= eidx)) return tree[idx];
	if(sidx == eidx){ //sidx == p
		return tree[idx] = n;
	}	
	ll midx = (sidx+eidx) >> 1;
	ll left = update(sidx, midx, p, n, LEFT(idx));
	ll right = update(midx+1, eidx, p, n, RIGHT(idx));

	return tree[idx] = (left * right) % MOD;
}

int main(){
	ll n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);

	for(ll i = 0; i < n; i ++) scanf("%lld", arr+i);
	init(0, n-1, 0);
	
	for(ll i = 0; i < m+k; i ++){
		ll a, b, c, x = 0;
		scanf("%lld %lld %lld", &a, &b, &c);
		switch(a){
		case 1:
			update(0, n-1, b-1, c, 0);
			arr[b-1] = c;
			break;
		case 2:
			x = product(0, n-1, b-1, c-1, 0);
			printf("%lld\n", x);
			break;
		}
	}

	return 0;
}
