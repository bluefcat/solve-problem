#include <stdio.h>
#define MAXM 1000000
#define MAXP 1500000

int arr[MAXP];

int main(){
    long long n;
    scanf("%lld", &n);
    
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < MAXP; i ++){
        arr[i] = (arr[i-1]+arr[i-2]) % MAXM;
    }
    
    printf("%d", arr[n%MAXP]);
    
    return 0;
}
