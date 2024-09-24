#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>

using complex = std::complex<double>;
using ll = long long;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 1002;

void fft(vector<complex>& f, bool inv){
	int n = f.size();
	if(n == 1) return;

	for(int i = 1, j = 0; i < n; i ++){
		int bit = n / 2;

		while(j >= bit){
			j -= bit;
			bit /= 2;
		}

		j += bit;
		if(i < j) std::swap(f[i], f[j]);
	}

	for(int k = 1; k < n; k <<= 1){
		double angle = inv?pi/k:-pi/k;
		complex w{cos(angle), sin(angle)};

		for(int i = 0; i < n; i += (k << 1)){
			complex wi{1, 0};

			for(int j = 0; j < k; j ++){
				complex even = f[i+j];
				complex odd = f[i+j+k];
				f[i+j] = even + wi * odd;
				f[i+j+k] = even - wi * odd;
				wi *= w;
			}
		}
	}
}

void mul(vector<complex>& x, vector<complex>& y){
	vector<complex> tmpx(x);
	vector<complex> tmpy(y);

	ll n = 1;
	while(n <= tmpx.size() || n <= tmpy.size()) n <<= 1;
	tmpx.resize(n);
	tmpy.resize(n);

	fft(tmpx, false); fft(tmpy, false);
	for(int i = 0; i < n; i ++){
		tmpx[i] *= tmpy[i];
	}
	fft(tmpx, true); 
	
	x.resize(n);
	for(int i = 0; i < n; i ++){
		if(round(tmpx[i].real())) x[i] = { 1, 0 };
		else x[i] = { 0, 0 };
	}
}

int main(){
	int n, k;
	int max_v, min_v;
	scanf("%d %d", &n, &k);
	vector<complex> x(N, 0);
	for(int i = 0; i < n; i ++){
		int v;
		scanf("%d", &v);
		if(i == 0){
			max_v = v; min_v = v;
		}
		max_v = std::max(max_v, v);
		min_v = std::min(min_v, v);
		x[v] = { 1, 0 };
	}

	vector<complex> r(x);
	int p = k-1;
	while(p){
		if(p & 1) mul(r, x);
		mul(x, x);
		p >>= 1;
	}

	for(int i = min_v*k; i <= max_v*k; i ++){
		if((ll)r[i].real() != 0)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
