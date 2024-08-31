#include <cstdio>
#include <vector>
#include <complex>

using std::vector;
using complex = std::complex<double>;
constexpr int N = 1000001;
constexpr double PI = 3.141592653589;
bool prime[N] = { false, };

void get_prime(){
	prime[2] = true;	
	for(int i = 3; i < N; i += 2) prime[i] = true;
	for(int i = 3; i < N; i += 2){
		if(!prime[i]) continue;
		for(int j = 2; j * i < N; j ++)
			prime[i*j] = false;
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
		double angle = inv?PI/k:-PI/k;
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
	get_prime();
	int size = 1;	
	while(N+2 > size) size <<= 1;
	size <<= 1;
	vector<complex> p(size, 0), q(size, 0);
	for(int i = 2; i < N; i ++){
		if(prime[i]){
			if(i > 2) p[i] = { 1, 0 };
			if(N > i*2) q[i*2] = { 1, 0 };
		}
	}
	
	fft(p, false);
	fft(q, false);
	for(int i = 0; i < size; i ++) p[i] *= q[i];
	fft(p, true);

	for(int i = 0; i < size; i ++){
		p[i] /= complex(size, 0);
		p[i] = complex(std::round(p[i].real()), std::round(p[i].imag()));
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int x;
		scanf("%d", &x);
		printf("%d\n", (int)p[x].real());
	}

	return 0;
}
