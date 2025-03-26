#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 200001;

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
		f[i] = even[i] + wi * odd[i];
		f[i+(n>>1)] = even[i] - wi * odd[i];
		wi *= w;
	}
}

int main(){
	int n, d, result = 0, size = 1;
	n = N;
	//scanf("%d", &n);
	
	while(N+2 > size) size <<= 1;
	size <<= 1;

	vector<complex> f(size, 0);
	vector<complex> g(size, 0);
	complex w(std::cos(2*pi/size), std::sin(2*pi/size));
	f[0] = 1;
	for(int i = 0; i < n; i ++){
		int x = i;
		//scanf("%d", &x);
		f[x] = {1, 0};
	}

	fft(f, w);
	for(int i = 0; i < size; i ++) g[i] = f[i]*f[i];
	fft(g, complex(1, 0)/w);
	return 0;
	for(int i = 0; i < size; i ++){
		g[i] /= complex(size, 0);
		g[i] = complex(round(g[i].real()), round(g[i].imag()));
	}
	long long answer = 0;
	scanf("%d", &d);
	for(int i = 0; i < d; i ++){
		int x;
		scanf("%d", &x);
		if((int)g[x].real() != 0) answer++;
	}

	printf("%lld\n", answer);

	return 0;
}
