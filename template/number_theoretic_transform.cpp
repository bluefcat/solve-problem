#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;
using lint = long long;

constexpr double pi = 3.14159265358979;
constexpr lint A = 3;
constexpr lint B = 30;
constexpr lint X = 5;
constexpr lint P = (A * (1 << B)) + 1;

lint mpow(lint x, lint e){
	lint result = 1;
	while(e){
		if(e & 1) result = (result * x) % P;
		x = (x * x) % P;
		e >>= 1;
	}
	return result;
}

void ntt(vector<lint>& f, bool inv){
	int n = f.size();
	if(n == 1) return;

	for(int i = 1, j = 0; i < n; i ++){
		int bit = n >> 1;

		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}

		j += bit;
		if(i < j) std::swap(f[i], f[j]);
	}

	for(int k = 1; k < n; k <<= 1){
		lint w = pow(inv?pow(X, P-2):X, P/k >> 1);

		for(int i = 0; i < n; i += (k << 1)){
			lint wi = 1;
			for(int j = 0; j < k; j ++){
				lint even = f[i+j];
				lint odd = f[i+j+k];
				f[i+j] = (even + (wi * odd)%P)%P;
				f[i+j+k] = (even - (wi * odd)%P)%P;
				wi = (wi * w) % P;
			}
		}
	}
	if(inv){
		lint det = pow(n, P-2);
		//M^-1 = 1/n * (M that w has negative angle)
		for(int i = 0; i < n; i++) f[i] = (f[i]*det) % P;
	}
}
