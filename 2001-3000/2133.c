#include <stdio.h>

int cache[31];

int main(){
	int n;
	scanf("%d", &n);
	
	cache[2] = 3;

	for(int i = 3; i <= n; i ++){
		int tmp = 0;

		for(int j = 2; j <= n; j += 2){
			int x = cache[i-j];
			int y = cache[j];
			
			tmp += x+y;
			if((x == 0 || y == 0) && i != j){
				tmp = 0;
				break;
			}
		}

		cache[i] = tmp;
	}

	printf("%d\n", cache[n]);

	return 0;
}
