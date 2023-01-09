#include <stdio.h>

int main(){
    unsigned long result = 0;

    unsigned long s[3] = { 0, };
    unsigned long x[3] = { 0, };

    scanf("%ld %ld %ld", s+0, s+1, s+2);
    scanf("%ld %ld %ld", x+0, x+1, x+2);

    int flag = 0;
    do{
        flag = 0;
        for(int i = 0; i < 3; i ++){
            //식권 다쓰기
            if(s[i] >= x[i]){
                result += x[i];
                s[i] -= x[i];
                x[i] = 0;
            }
            else{
                result += s[i];
                x[i] -= s[i];
                s[i] = 0;
            }
            //식권 교환하기
            unsigned long tmp = x[i];

            if(tmp < 3) continue;
            if(s[i] == 0){
                x[i] = tmp % 3;
                x[(i+1)%3] = tmp / 3;
            }
            flag = 1;
        }
    }while(flag);

    
    printf("%ld\n", result);

    return 0;
}