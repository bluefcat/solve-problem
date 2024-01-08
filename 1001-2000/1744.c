#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
    return *(int*)y - *(int*)x;
}

int main(){    
    int n, result = 0;    
    int cache[51] = { 0, };    
    
    scanf("%d", &n);    
    for(int i = 0; i < n; i ++) scanf("%d", cache+i);    
    
    qsort(cache, n, sizeof(int), compare);    
        
    int p = (cache[n-1] > 0)? n: 0;    
    int m = (cache[0] < 0)? 0: n;    
    
    for(int i = 0; i < n-1; i ++){    
        int x = cache[i];    
        int y = cache[i+1];    
            
        if(x > 0 && !(y > 0)) p = i+1;    
        if(y < 0 && !(x < 0)) m = i+1;    
    }    
        
    int z = (m - p) > 0? (m - p): 0;    
    int i = 0;    
    for(i = 0; i < p-1; i +=2){    
        int x = cache[i];     
        int y = cache[i+1];    
        if(y == 1) result += x+y;
		else result += x*y;      
    }    
    if(p & 1) result += cache[i];    
    
    for(i = n-1; i >= m+1; i -=2){    
        int x = cache[i];    
        int y = cache[i-1];    
        result += x*y;    
    }    
    if(((n-m)&1) && z == 0){    
        result += cache[m];    
    }    
    
    printf("%d\n", result);    
    
    return 0;    
}