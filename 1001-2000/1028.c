#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[751][751];
int cache[751][751];
int R, C, result;

int main(){
	scanf("%d %d", &R, &C);

	for(int i = 1; i <= R; i ++){
		for(int j = 1; j <= C; j ++) scanf("%d", map[R] + C);
	}
	
	result = 1;

	for(int i = 1; i <= R; i ++){
		for(int j = 1; j <= C; j ++){
			
		}
	}



	return 0;
}
