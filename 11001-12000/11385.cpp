#include <cstdio>
#include <vector>

using std::vector;
using lint = __int128;

const lint A = 130'851, B = 45, P = (A << B) | 1, R = 5; 

//2'281'701'377
//const lint A = 17, B = 27, P = (A << B) | 1, R = 3; 
//2'013'265'921
//const lint A = 15, B = 27, P = (A << B) | 1, R = 31; 
//469'762'049
//const lint A = 7, B = 26, P = (A << B) | 1, R = 3; 
//998'244'353
//const lint A = 119, B = 23, P = (A << B) | 1, R = 3;

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

void print(lint x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main(){
	lint size = (1 << 20);	
	vector<lint> p(size, 0), q(size, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	for(lint i = 0; i < n+1; i ++){
		int x;
		scanf("%d", &x);
		p[i] = x;
	}
	for(lint i = 0; i < m+1; i ++){
		int x;
		scanf("%d", &x);
		q[i] = x;
	}
	
	ntt(p, false);
	ntt(q, false);
	for(lint i = 0; i < size; i ++) p[i] = (p[i] * q[i]) % P;
	ntt(p, true);
	
	lint result = 0;

	for(lint i = 0; i < (n+1)*(m+1); i ++){
		result ^= p[i];
	}
	print(result);
	printf("\n");

	return 0;
}
