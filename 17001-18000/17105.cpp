#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 2000001;
constexpr int Q = 1000001;

void set_prime(vector<complex>& f){
	for(int i = 2; i < Q; i ++)
		f[i] = { 1, 0 };
	
	for(int i = 2; i < Q; i ++){
		if((int)f[i].real() == 0) continue; 
		for(int j = 2; i*j < Q; j ++){
			f[i*j] = { 0, 0 };
		}
	}
}

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
	int n, size = 1;
	while(N > size) size <<= 1;
	size <<= 1;
	vector<complex> f(size, 0);
	vector<complex> g(size, 0);
	set_prime(f);

	fft(f, false);
	for(int i = 0; i < size; i ++){
		f[i] = f[i]*f[i];
		g[i] = f[i];
	} 
	fft(f, true);
	
	for(int i = 0; i < size; i ++){
		f[i] /= complex(size, 0);
		f[i] = complex(round(f[i].real()), round(f[i].imag()));
	}

	return 0;
	int t;
	scanf("%d", &t);
	while(t--){
		int x;
		scanf("%d", &x);
		long long result = (long long)(f[x].real());
		//result = (result / 2) + (result & 1);
		printf("%lld\n", result);
	}

	return 0;
}
