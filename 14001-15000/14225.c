#include <stdio.h>
#define NMAX 21
#define NUMMAX 30

int array[NMAX];
int checker[NUMMAX];

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", array + i);

	for(int i = 0; i < n; i ++){
		checker[array[i]] = 1;

		for(int j = 0; j < NUMMAX; j ++){
			if(checker[j] == 0) continue;

			checker[j + array[i]] = 1;
		}

	}
	
	
	for(int i = 1; i < NUMMAX; i ++){
		printf("%d %d\n", i, checker[i]);
		if(checker[i] == 0){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
