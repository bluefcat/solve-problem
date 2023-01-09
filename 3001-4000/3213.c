#include <stdio.h>
#define N 10000
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int main(){
    int result = 0;
    
    int half = 0;  // 1/2
    int quar = 0;  // 1/4
    int tquar = 0; // 3/4

    int n = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++){
        int num, dec;
        scanf("%d/%d", &num, &dec);

        if(dec == 2) 
            half ++;
        else{
            if(num == 1)
                quar ++;
            else
                tquar ++;
        }
    }

    int remain = 0;
    
    result += (half / 2) + (half % 2);
    remain += 2 * (half % 2);

    int q_count = MIN(quar, tquar);
    result += q_count;

    quar -= q_count;
    tquar -= q_count;

    quar = MAX(0, quar - remain);
    result += quar/4 + (quar % 4 ? 1: 0);

    result += tquar;

    printf("%d\n", result);

    return 0;
}