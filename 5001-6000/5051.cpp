#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 500001;

void set_square(vector<complex>& f, int n){
	for(int i = 1; i < n; i++){
		double cand = f[(i*i)%n].real();
		f[(i*i)%n] = {cand + 1, 0};
	}
}

void fft(vector<complex>& f, complex w){
	int n = f.size();
	if(n == 1) return;
	
	vector<complex> even(n>>1), odd(n>>1);
	for(int i = 0; i < n; i ++){
		if(i&1) odd[i>>1] = f[i];
		else even[i>>1] = f[i];
	}

	fft(even, w*w);
	fft(odd, w*w);

	complex wi(1, 0);
	for(int i = 0; i < (n >> 1); i ++){
		f[i] = even[i] + wi*odd[i];
		f[i+(n >> 1)] = even[i] - wi*odd[i];
		wi *= w;
	}
}


int main(){
	int size = 1;
	int x;
	scanf("%d", &x);
	while(N > size) size <<= 1;
	size <<= 1;
	vector<complex> f(size, 0);
	set_square(f, x);
	vector<complex> filter(f);

	complex w(std::cos(2*pi/size), std::sin(2*pi/size));
	fft(f, w);
	for(int i = 0; i < size; i ++) f[i] *= f[i];
	fft(f, complex(1, 0)/w);

	for(int i = 0; i < size; i ++){
		f[i] /= complex(size, 0);
		f[i%x] += complex(round(f[i].real()), round(f[i].imag()));
		f[i] = { 0, 0 };
	}

	int result = 0, s = 0;
	for(int i = 1; i < x; i ++){
		if((int)filter[i].real() == 0) continue;
		int tmp = (int)(f[i%x].real());
		result += tmp;
	}
	printf("%d\n", result);
	return 0;
}
