#include <stdio.h>

#define CUBE(X) (X*X*X)
int main(){

	for(int a = 1; a <= 100; a ++){
		int x = 1, y = 1, z = 1;

		int t = CUBE(a);
		for(x = 1; CUBE(x) + CUBE(y) + CUBE(z) <= t; x ++){
			for(y = 1; CUBE(x) + CUBE(y) + CUBE(z) <= t; y ++){
				for(z = 1; CUBE(x) + CUBE(y) + CUBE(z) <= t; z ++){;
					if(CUBE(x) + CUBE(y) + CUBE(z) == t){
						printf("Cube = %d, Triple = (%d, %d, %d)\n", a, x, y, z);
					}
				}
				z = 1;
			}
			y = 1;
		}
		x = 1;
		INIT:
		continue;

	}

	return 0;
}
