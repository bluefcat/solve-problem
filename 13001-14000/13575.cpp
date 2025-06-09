#include <cstdio>
#include <vector>

using std::vector;
using lint = long long;

//3'221'225'473
//const lint A = 3, B = 30, P = (A << B) | 1, R = 5; 
//2'281'701'377
//const lint A = 17, B = 27, P = (A << B) | 1, R = 3; 
//2'013'265'921
//const lint A = 15, B = 27, P = (A << B) | 1, R = 31; 
//469'762'049
//const lint A = 7, B = 26, P = (A << B) | 1, R = 3; 
//998'244'353
const lint A = 119, B = 23, P = (A << B) | 1, R = 3;

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
vector<lint> mul(vector<lint>& x, vector<lint>& y){
	vector<lint> tmpx(x.begin(), x.end());
	vector<lint> tmpy(y.begin(), y.end());

	int n = 1;
	while(n <= tmpx.size() || n <= tmpy.size()) 
        n <<= 1;
    tmpx.resize(n); tmpy.resize(n);
	ntt(tmpx, false); ntt(tmpy, false);
	
    for(int i = 0; i < n; i ++) tmpx[i] *= tmpy[i];

	ntt(tmpx, true); 
	
	vector<lint> result(n);
	for(int i = 0; i < n; i ++){
		if(tmpx[i] != 0) 
            result[i] = 1;
	}
	return result;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<lint> x(1024);
	for(int i = 0; i < n; i ++){
		int v;
		scanf("%d", &v);
		x[v] = 1;
	}

	vector<lint> r(x.begin(), x.end());
	int p = k-1;
	while(p){
		if(p & 1) r = mul(r, x);
		x = mul(x, x);
		p >>= 1;
	}

	for(int i = 0; i < r.size(); i ++){
		if(r[i] != 0)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}
