#include <cstdio>

using ll = long long;

int main(){
    int n, m, k, f = 0;
    ll r1 = 0;
    scanf("%d %d %d", &n, &m, &k);
    ll result = 0;
    for(int i = 0; i < m; i ++){
        ll t, x;
        scanf("%lld %lld", &t, &x);
        result += x;
        if(result > k && f == 0){
            r1 = i+1;
            f = 1;
        }
    }
    if(r1 != 0){
        printf("%lld 1\n", r1);
    }
    else
    printf("-1\n");

    return 0;
}