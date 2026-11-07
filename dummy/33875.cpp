#include <cstdio>

int field[2*10'000][2*10'000];

int main(){
    int h, w;
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            scanf("%1d", field[i] + j);
        }
    }

    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            
        }
    }


    printf("%d\n", stage);
    return 0;
}