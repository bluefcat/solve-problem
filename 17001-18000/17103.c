#include <stdio.h>
#define MAX 1000001

char prime[MAX];

int main(){
	for(int i = 0; i < MAX;i ++) prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;

	for(int i = 2; i < MAX; i ++){
		if(prime[i] == 0) continue;
		for(int j = 2; j < MAX/i+1; j ++) 
			prime[i*j] = 0;		
	}
	
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		int answer = 0;
		for(int i = 2; i < n/2+1; i ++){
			if(prime[i] == 1 && (prime[i] == prime[n-i])) answer ++;
		}
		printf("%d\n", answer);
	}
	return 0;
}
