#include <bits/stdc++.h>

const double PI = acos(-1);
using complex = std::complex<double>;

void FFT(std::vector<complex> &vec, bool inv){
    int size = vec.size();

    for(int i = 1, j = 0; i < size; i ++){
        int bit = size/2;

        while(j >= bit){
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(vec[i], vec[j]);
    }

    for(int k = 1; k < size; k <<= 1){
        double angle = (inv ? PI/k : -PI/k);   
        complex w{cos(angle), sin(angle)};

        for(int i = 0; i < size; i += (k << 1)){
            complex z{1, 0};

            for(int j = 0; j < k; j ++){
                complex even = vec[i+j];
                complex odd = vec[i+j+k];

                vec[i+j] = even + z * odd;
                vec[i+j+k] = even - z * odd;

                z *= w;
            }
        }
    }

    if(inv) for(int i = 0; i < size; i ++) vec[i] /= size;
    return ;
}

std::vector<int> mul(std::vector<int> &v, std::vector<int> &u){
    std::vector<complex> vc(v.begin(), v.end());
    std::vector<complex> uc(u.begin(), u.end());

    int size = 2;
    while(size < v.size() + u.size()) size <<= 1;

    vc.resize(size); FFT(vc, false);
    uc.resize(size); FFT(uc, false);

    for(int i = 0; i < size; i ++) vc[i] *= uc[i];
    FFT(vc, true);

    std::vector<int> w(size);
    for(int i = 0; i < size; i ++) w[i] = round(vc[i].real());

    return w;
}

int main(){
    char x[300001] = { 0, };
    char y[300001] = { 0, };

    scanf("%s %s", x, y);

    if(x[0] == '0' || y[0] == '0'){
        printf("0\n");
        return 0;
    }

    std::vector<int> v(strlen(x));
    std::vector<int> u(strlen(y));

    for(int i = 0; i < strlen(x); i ++) v[strlen(x) - i - 1] = x[i] - '0';
    for(int j = 0; j < strlen(y); j ++) u[strlen(y) - j - 1] = y[j] - '0';


    std::vector<int> w = mul(v, u);

    for (int i = 0; i < v.size() + u.size() - 1; i++) {
        w[i + 1] += w[i] / 10;
        w[i] = w[i] % 10;
    }

    int cnt = w.size() - 1;

    while (w[cnt] == 0) {
        cnt--;
        if (cnt == 0) break;
    }
    for (int i = cnt; i >= 0; i--) printf("%d", w[i]);
    printf("\n");
    return 0;
}
