#include <cstdio>
#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;
using lint = long long;

const lint A = 7, B = 26, P = (A << B) | 1, R = 3;

lint pow(lint x, lint e, lint mod = P){
	lint result = 1;
	while(e){
		if(e & 1) result = (result * x) % mod;
		x = (x * x) % mod;
		e >>= 1;
	}
	return result;
}

void ntt(vector<lint>& f, bool inv = false){
	lint n = f.size();
	if(n == 1) return;

	for(lint i = 1, j = 0; i < n; i ++){
		lint bit = n >> 1;
		for(;j&bit; bit >>= 1) j^=bit;
		j ^= bit;

		if(i < j) std::swap(f[i], f[j]);
	}

	for(lint k = 1; k < n; k <<= 1){
		lint w = pow(inv?pow(R,P-2):R, P / k >> 1);

		for(lint i = 0; i < n; i += (k << 1)){
			lint wi=1;

			for(lint j = 0; j < k; j ++){
				lint even = f[i+j];
				lint odd = (f[i+j+k] * wi) % P;
				f[i+j] = (even + odd) % P;
				f[i+j+k] = (even - odd + P) % P; 
				wi = (wi*w) % P;
			}
		}
	}
	if(inv){
		lint ip = pow(n, P-2);
		//M^-1 = 1/n * (M that w has negative angle)
		for(lint& x: f)
			x = (x * ip) % P;
	}
}

vector<lint> f{};
vector<lint> g{};
int main(){
	lint n;
	scanf("%lld", &n);

	f.resize(1 << 20);
	g.resize(1 << 20);
	
	for(lint i = 0; i < n; i ++){
		lint tmp ;
		scanf("%lld", &tmp);
		f[i] = tmp;
		f[i+n] = tmp;
	}

	for(lint i = 0; i < n; i ++){
		lint tmp;
		scanf("%lld", &tmp);
		g[n-i-1] = tmp;
	}
	

	ntt(f); ntt(g);

	for(lint i = 0; i < (1 << 20); i ++) f[i] = (f[i] * g[i]) % P;

	ntt(f, true);

	lint result = 0;
	for(int i = 0; i < (1 << 20);i ++)
		if(f[i] > result) result = f[i];
	
	printf("%lld\n", result);

	return 0;
}
