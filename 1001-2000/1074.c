#include <stdio.h>

int mpow(int base, int e){
	int result = 1;
	for(int i = 0; i < e; i ++){
		result *= base;
	}

	return result;
}

void sub_solve(int r, int c){
	
	sub_solve(r>>1, c>>1);

}

void solve(n){
	
}

int main(){
	int n;
	scanf("%d", &n);
	n = mpow(2, n);
	
	solve(n);
}
