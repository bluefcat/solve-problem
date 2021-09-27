#include <stdio.h>
#define MIN(X, Y) ((X) > (Y)?(Y): (X))

typedef struct zeros_{
    int two;
    int five;
} zeros;

zeros fact_count(int n){
	zeros result;
    result.two = 0;
    result.five = 0;

	for(int i = 1; i <= n; i ++){
		for(int t = i; t % 2 == 0; t >>= 1){
			result.two ++;
		}

		for(int t = i; t % 5 == 0; t /= 5){
			result.five ++;
		}


	}
	return result;
}

int main(){

	
	int n, m;
	int result = 0;

	scanf("%d %d", &n, &m);

	zeros a = fact_count(n);
    zeros b = fact_count(m);
    zeros c = fact_count(n-m);

    printf("%d %d\n", a.two, a.five);
    printf("%d %d\n", b.two, b.five);
    printf("%d %d\n", c.two, c.five);
    printf("===\n");

    result = MIN((a.two - (b.two + c.two)), (a.five - (b.five + c.five)));
    printf("%d\n", result);
	
	return 0;
}
