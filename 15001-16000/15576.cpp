#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>

using complex = std::complex<double>;
using ll = long long;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 300002;

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
	ll size = 1;
	while(N+1 > size) size <<= 1;
	size <<= 1;
	vector<complex> x(size, 0), y(size, 0);
	int result[N*2] = { 0, };
	
	int xidx = 0, yidx = 0;
	char tmp;
	while(scanf("%c", &tmp) != EOF && tmp != ' '){
		x[xidx++] = { (double)(tmp-'0'), 0 };
	}

	while(scanf("%c", &tmp) != EOF && tmp != ' ' && tmp != '\n'){
		y[yidx++] = { (double)(tmp-'0'), 0 };
	}


	fft(x, false); fft(y, false);
	for(int i = 0; i < size; i ++) x[i] *= y[i];
	fft(x, true);
	
	int length = xidx+yidx-2;
	ll carry = 0;
	for(int i = length; i >= 0; i --){
		x[i] /= complex(size, 0);
		x[i] = {round(x[i].real()), round(x[i].imag())};
		ll tmp = (ll)x[i].real();
		ll calc = tmp % 10 + carry % 10;
		result[length-i] = calc % 10;
		carry = tmp / 10 + carry/10 + calc/10;
	}

	if(carry != 0 ) printf("%lld", carry);
	for(int i = length; i >= 0; i--)
		printf("%d", result[i]);
	printf("\n");


	return 0;
}
