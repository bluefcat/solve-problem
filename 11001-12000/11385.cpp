#include <cstdio>

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

constexpr lint size = ((lint)1 << 23);	
lint R1 = pow(R, P-2);
lint ip = pow(size, P-2);
void ntt(lint* f, bool inv = false){
	lint n = size;
	if(n == 1) return;

	for(lint i = 1, j = 0; i < n; i ++){
		lint k = n >> 1;
		for(; j>= k; k >>= 1) j -= k;
		j += k;

		if(i < j){
			lint tmp = f[i];
			f[i] = f[j];
			f[j] = tmp;
		}
	}

	for(lint k = 1; k < n; k <<= 1){
		lint w = pow(inv?R1:R, P / k >> 1);

		for(lint i = 0; i < n; i += (k << 1)){
			lint wi=1;

			for(lint j = 0; j < k; j ++){
				//lint even = f[i+j];
				//lint odd = (f[i+j+k] * wi) % P;
				//f[i+j] = (even + odd) % P;
				//f[i+j+k] = (even - odd + P) % P; 
				lint odd = (f[k|i|j] * wi) % P;
				f[k|i|j] = f[i|j] - odd;
				if(f[k|i|j] < 0) f[k|i|j] += P;
				f[i|j] += odd;
				if(f[i|j] >= P) f[i|j] -= P; 
				wi = (wi*w) % P;
			}
		}
	}
	if(inv){
		//M^-1 = 1/n * (M that w has negative angle)
		for(lint i = 0; i < n; i ++)
			f[i] = (f[i] * ip) % P;
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

lint p[size];
lint q[size];

int main(){
	long long n, m;
	scanf("%lld %lld", &n, &m);
	for(lint i = 0; i < n+1; i ++){
		int x;
		scanf("%d", &x);
		p[i] = (lint)x;
	}
	for(lint i = 0; i < m+1; i ++){
		int x;
		scanf("%d", &x);
		q[i] = (lint)x;
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
