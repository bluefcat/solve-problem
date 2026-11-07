#include <cstdio>
#include <algorithm>

using ldouble = long double;

constexpr int N = 50;
constexpr ldouble MAXLEN = 5 * 100000000000000 + 1;
//constexpr ldouble MAXLEN = 100;
constexpr ldouble ERROR = 0.00000000001;
int n;
ldouble c;
ldouble t[N] = { 0, };
ldouble x[N] = { 0, };
ldouble result = MAXLEN+1;


bool get_result(ldouble r){
    ldouble sum = 0.L;
    for(int i = 0; i < n; i ++){
        if(sum + std::max(x[i]-r, 0.L) * t[i] > c + ERROR) return false;
        sum = std::max(sum + x[i] * t[i] - r * t[i], 0.L);
    }
    return true;
}

int main(){
    scanf("%d %Lf", &n, &c);
    for(int i = 0; i < n; i ++) scanf("%Lf", t+i);
    for(int i = 0; i < n; i ++) scanf("%Lf", x+i);

    ldouble l = 0, r = MAXLEN;

    for(int i = 0; i < 100; i ++){
        ldouble m = (l + r) / 2.L;
        bool flag = get_result(m);

        if(flag){
            result = std::min(result, m);
            r = m;
        }
        else{
            l = m;
        }
    }

    if(result > MAXLEN) result = 0.0L;
    printf("%.16Lf\n", result);
    return 0;
}