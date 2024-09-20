#include <cstdio>
#include <vector>
#include <complex>

using std::vector;
using complex = std::complex<long double>;
constexpr int N = 1000001;
constexpr long double PI = 3.141592653589;

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

void print(__int128 x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main(){
	int size = 1;	
	while(N+2 > size) size <<= 1;
	size <<= 1;
	vector<complex> p(size, 0), q(size, 0);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n+1; i ++){
		int x;
		scanf("%d", &x);
		p[i] = x;
	}
	for(int i = 0; i < m+1; i ++){
		int x;
		scanf("%d", &x);
		q[i] = x;
	}
	
	fft(p, false);
	fft(q, false);
	for(int i = 0; i < size; i ++) p[i] *= q[i];
	fft(p, true);
	
	__int128 result = 0;

	for(int i = 0; i < (n+1)*(m+1); i ++){
		p[i] /= complex(size, 0);
		p[i] = complex(std::round(p[i].real()), std::round(p[i].imag()));
		result ^= (__int128)p[i].real();
	}
	print(result);
	printf("\n");

	return 0;
}
