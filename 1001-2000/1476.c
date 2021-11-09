#include <stdio.h>

#define P(X, Y) ((X+1) % Y) 

int main(){
	int E, S, M;
	int e = 0, s = 0, m = 0;
	int result = 1;

	scanf("%d %d %d", &E, &S, &M);
	E --; S --; M --;
	
	while(E != e || S != s || M != m){
		e = P(e, 15);
		s = P(s, 28);
		m = P(m, 19);
		
		result ++;
	}

	printf("%d\n", result);

	return 0;
}
