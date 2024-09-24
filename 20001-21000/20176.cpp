#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;
using ll = long long;

constexpr double pi = 3.14159265358979;
constexpr ll N = 30001;

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


int main(){
	int size = 1;
	while((2*N) > size) size <<= 1;
	size <<= 1;
	vector<complex> f(size, 0);
	vector<complex> g(size, 0);
	vector<complex> h(size, 0);

	int n, m, k, ix;
	ll result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &ix);
		f[N+ix] = { 1, 0 };
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		scanf("%d", &ix);
		g[N+ix] = { 1, 0 };
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i ++){
		scanf("%d", &ix);
		h[N+ix] = { 1, 0 };
	}

	fft(f, false); fft(h, false);
	for(int i = 0; i < size; i ++){ 
		f[i] *= h[i];
	}
	fft(f, true);

	for(int i = 0; i < size; i ++){
		f[i] /= complex(size, 0);
		f[i] = complex(round(f[i].real()), round(f[i].imag()));

	}

	for(int i = 0; i < 2*N; i ++)
		result += g[i].real() * f[2*i].real();
	printf("%lld\n", result);


	return 0;
}
