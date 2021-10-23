#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) < (Y))? (X): (Y))

int main(){
	int a[3] = { 0, };
	scanf("%d %d %d", a, a+1, a+2);
	
	int min = MIN(a[0], MIN(a[1], a[2]));
	int max = MAX(a[0], MAX(a[1], a[2]));
	
	int min_count = 0;
	int max_count = 0;

	for(int i = 0; i < 3; i ++){
		if(a[i] == min) min_count ++;
		if(a[i] == max) max_count ++;
	}

	if(min_count > 1){
		printf("%d\n", min);
		return 0;
	}
	if(max_count > 1){
		printf("%d\n", max);
		return 0;
	}

	for(int i = 0; i < 3; i ++){
		if(min < a[i] && a[i] < max){
			printf("%d\n", a[i]);
			return 0;
		}
	}

	return 0;
}
