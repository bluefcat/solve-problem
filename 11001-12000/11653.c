#include <stdio.h>

int main(){

	//init find prime number in sqrt(10000000)
	int cache[3201] = { 1, };
	for(int i = 2; i < 3201; i ++) cache[i] = 1;

	int cur = 2;
	while(cur <= 3201){
		if(cache[cur] == 1)
			for(int i = cur+cur; i <= 3200; i += cur)
				cache[i] = 0;

		cur ++;
	}
	
	//solve problem
	int n;
	scanf("%d", &n);

	int i = 2;
	while(n > 1 && i < 3201){
		if(cache[i] == 0){
			i ++;
		}
		else if(n % i){
			i ++;
		}
		else{
			printf("%d\n", i);
			n /= i;
		}
	}

    if(n > 1) printf("%d\n", n);

	return 0;
}