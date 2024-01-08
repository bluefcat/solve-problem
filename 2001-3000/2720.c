#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    int cash[4] = {25, 10, 5, 1};
    while(t--){
        int result[4] = {0, 0, 0, 0};
        int n;
        scanf("%d", &n);

        for(int i = 0; i < 4; i ++){
            result[i] = n / cash[i];
            n %= cash[i];
        }

        printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);

    }
    return 0;
}