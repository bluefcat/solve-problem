#include <stdio.h>

#define NMAX 10000001

int prime[NMAX];

int main(){
	for(int i = 0; i < NMAX; i ++) prime[i] = 1;
	prime[0] = 0; prime[1] = 0;

	for(int i = 2; i < NMAX; i ++){
		if(prime[i] == 0) continue;
		
		for(int j = 2; i * j < NMAX; j ++){
			prime[i * j] = 0;
		}
	}

	int n;
	scanf("%d", &n);
	for(int i = n; i < NMAX; i ++){
		if(prime[i] == 0) continue;
		
		int length = 0;
		int tmp = i;
		while(tmp > 0){
			length ++; tmp /= 10;
		}
		
		//palindrome check 
		int l = length-1, r = 0;
		while(l >= r){
			int lt = i, rt = i;
			for(int a = 0; a < l; a ++) lt /= 10;
			for(int a = 0; a < r; a ++) rt /= 10;

			if(lt % 10 != rt % 10){
				goto NXT;		
			}

			l --;
			r ++;
		}
		printf("%d\n", i);
		break;

		NXT:
			continue;
	}

	return 0;
}
