#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int h[1001][3];
int m[1001][3];

int coloring(int n){
	m[0][0] = h[0][0];
	m[0][1] = h[0][1];
	m[0][2] = h[0][2];

	for(int i = 1; i <= n; i ++){
		m[i][0] = MIN(m[i-1][1], m[i-1][2]) + h[i][0];
		m[i][1] = MIN(m[i-1][0], m[i-1][2]) + h[i][1];
		m[i][2] = MIN(m[i-1][0], m[i-1][1]) + h[i][2];
	}

	return MIN(m[n][0], MIN(m[n][1], m[n][2]));
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d %d %d", h[i]+0, h[i]+1, h[i]+2);
	}
	printf("%d\n", coloring(n));

	return 0;
}
