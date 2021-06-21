#include <stdio.h>
#include <limits.h>

int main(void){
    int k, n;
    long long m[10001] = { 0, };
    long long max = 0;
    scanf("%d %d", &k, &n);
    
    for (int i = 0; i < k; i++){
        scanf("%lld", m+i);
	}

 
    long long left = 0;
    long long right = LLONG_MAX;
 
    while (left <= right){
		int result = 0;
        long long mid = (left + right) / 2;
        
        for (int i = 0; i < k; i++){
			result += m[i] / mid;
		}

 
        if (result >= n)
        {
            left = mid + 1;
            if (mid > max)
                max = mid;
        }
        else{
            right = mid - 1;
		}
    }
 
    printf("%lld\n", max);
 
 
    return 0;
}

