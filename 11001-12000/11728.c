#include <stdio.h>

#define ASIZE 1000001

int A[ASIZE];
int B[ASIZE];
int F[ASIZE << 1];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++) scanf("%d", A+i);
	for(int i = 0; i < m; i ++) scanf("%d", B+i);

	int idx = 0, i = 0, j = 0;

	while(i < n || j < m){
		if(i >= n){
			F[idx++] = B[j];
			j ++;
			continue;
		}
		if(j >= m){
			F[idx++] = A[i];
			i ++;
			continue;
		}

		if(A[i] < B[j]){
			F[idx++] = A[i];
			i++;
		}
		else{
			F[idx++] = B[j];
			j++;
		}
	}

	for(int i = 0; i < n+m; i ++) printf("%d ", F[i]);
	printf("\n");

	return 0;
}
