#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 1000001;

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
	int n, m, size = 1; 
	scanf("%d %d", &n, &m);
	
	while(n+1 > size) 
		size <<= 1;	
	size <<= 1;
	
	vector<complex> 
		ur(size, 0), up(size, 0), us(size, 0),
		vr(size, 0), vp(size, 0), vs(size, 0);

	for(int i = 0; i < n; i ++){
		char x;
		scanf(" %c", &x);
		switch(x){
			case 'R':
				ur[i] = {1, 0};
				break;
			case 'P':
				up[i] = {1, 0};
				break;
			case 'S':
				us[i] = {1, 0};
				break;
		}
	}

	for(int i = 0; i < m; i ++){
		char x;
		scanf(" %c", &x);
		switch(x){
			case 'R':
				vr[m-i-1] = {1, 0};
				break;
			case 'P':
				vp[m-i-1] = {1, 0};
				break;
			case 'S':
				vs[m-i-1] = {1, 0};
				break;
		}
	}

	fft(ur, false); fft(vr, false);
	fft(up, false); fft(vp, false);
	fft(us, false); fft(vs, false);
	for(int i = 0; i < size; i ++){
		ur[i] *= vp[i];
		up[i] *= vs[i];
		us[i] *= vr[i];
	}
	fft(ur, true);
	fft(up, true);
	fft(us, true);
	
	long long result = 0;
	for(int i = m-1; i < n; i ++){
		ur[i] /= complex(size, 0);
		up[i] /= complex(size, 0);
		us[i] /= complex(size, 0);
		ur[i] = complex(round(ur[i].real()), round(ur[i].imag()));
		up[i] = complex(round(up[i].real()), round(up[i].imag()));
		us[i] = complex(round(us[i].real()), round(us[i].imag()));

		long long x = (int)ur[i].real() + (int)up[i].real() + (int)us[i].real();
		result = std::max(result, x);
	}
	
	printf("%lld\n", result);

	return 0;
}
