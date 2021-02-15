#include <stdio.h>
#include <time.h>

int n, result = 0;
int board[15] = { 0, };

void nqueen(int x){
    if(x == n){
        result ++;
        return;
    }
    
    for(int i = 0; i < n; i ++){
        board[x] = i;
        int flag = 0;
        
        for(int j = 0; j < x; j ++){
            if(i == board[j]){
                flag = 1;
                break;
            }
            
            if(i == board[j]-(x-j) || i == board[j]+(x-j)){
                flag = 1;
                break;
            }
        }
        if(!flag) nqueen(x+1);
    }
    return;
}

int main(){
	clock_t start, end;
    scanf("%d", &n);
    
	start = clock();
    nqueen(0);
	end = clock();
    printf("%d\n", result);
    printf("%.3f\n", (float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}