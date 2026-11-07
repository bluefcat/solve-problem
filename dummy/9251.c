#include <stdio.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y))?(X): (Y))

char a[1001];
char b[1001];
int cache[1001][1001];


int solve(int x, int y){
    if(cache[x][y] != -1) return cache[x][y];

    cache[x][y] = MAX(cache[x][y], solve(x-1, y));
    cache[x][y] = MAX(cache[x][y], solve(x, y-1));
    cache[x][y] = MAX(cache[x][y], cache[x-1][y-1] + (a[x-1] == b[y-1]));

    return cache[x][y];
}


int main(){
    scanf("%s", a);
    scanf("%s", b);

    for(int i = 1; i < strlen(a)+1; i ++){
        for(int j = 1; j < strlen(b)+1; j ++) cache[i][j] = -1;
    }

    printf("%d\n", solve(strlen(a), strlen(b)));
    return 0;
}