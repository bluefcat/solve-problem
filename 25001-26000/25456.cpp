#include <cstdio>
#include <cstring>
#include <complex>
#include <vector>
#include <algorithm>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 500001;
char tmp[2][N] = { 0, };

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
	scanf("%s", tmp[0]);
	scanf("%s", tmp[1]);
	int ulen = strlen(tmp[0]);
	int vlen = strlen(tmp[1]);
	int len = 2*std::max(ulen, vlen);

	int size = 1;
	while(len > size) size <<= 1;
	size <<= 1;
	vector<complex> u(size, 0), v(size, 0);
	
	for(int i = 0; i < ulen; i ++){
		if(tmp[0][i] == '1'){
			u[i] = { 1, 0 };
			u[i+ulen] = { 1, 0 };
		}
	}

	for(int i = 0; i < vlen; i ++)
		if(tmp[1][vlen-(i+1)] == '1')
			v[i] = {1, 0};

	fft(u, false);
	fft(v, false);

	for(int i = 0; i < size; i ++) u[i] *= v[i];
	fft(u, true);

	int result = 0;
	for(int i = 0; i < size; i ++){
		u[i] /= complex(size, 0);
		u[i] = complex(round(u[i].real()), round(u[i].imag()));
		result = std::max(result, (int)(u[i].real()));
	}

	printf("%d\n", result);

	return 0;
}



