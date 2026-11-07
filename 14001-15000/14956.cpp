#include <cstdio>
#include <cmath>
using ll = long long;

void product(ll n[][2], ll m[][2]){
	ll tmp[2][2] = {{0, 0}, {0, 0}};
	tmp[0][0] = n[0][0] * m[0][0] + n[0][1] * m[1][0];
	tmp[0][1] = n[0][0] * m[0][1] + n[0][1] * m[1][1];
	tmp[1][0] = n[1][0] * m[0][0] + n[1][1] * m[1][0];
	tmp[1][1] = n[1][0] * m[0][1] + n[1][1] * m[1][1];
	n[0][0] = tmp[0][0]; n[0][1] = tmp[0][1]; n[1][0] = tmp[1][0]; n[1][1] = tmp[1][1];
}

int main(){
	ll transpose[2][2][2] = {{{0, 1}, {1, 0}}, {{0, -1}, {-1, 0}}};

	ll f[2][2] = {{1, 0}, {0, 1}};
	ll n, m;

	scanf("%lld %lld", &n ,&m);
	
	ll x = 0;
	ll y = 0;
	
	n = (ll)(log(n)/log(2)); m --;

	
	while(n > 0 || m > 0){
		
		ll pos[4][2] = {
			{0, 0}, 
			{0, pow(2, n-1)}, 
			{pow(2, n-1), pow(2, n-1)},
			{pow(2, n) - 1, pow(2, n-1) - 1}
		};
	
		ll p = pow(2, 2*(n-1));
		ll quadrant = (ll)(m / p);
		ll bias = p * quadrant;
		
		ll nx = pos[quadrant][0];
		ll ny = pos[quadrant][1];
		
		x += f[0][0] * nx + f[0][1] * ny;
		y += f[1][0] * nx + f[1][1] * ny;
		
		if(quadrant == 0 || quadrant == 3){
			int idx = quadrant == 0 ? 0: 1;
			product(f, transpose[idx]);
		}

		n -= 1;
		m -= bias;
	}


	printf("%lld %lld\n", x+1, y+1);


	return 0;
}
