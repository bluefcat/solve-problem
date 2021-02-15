#include <stdio.h>

void solve_hanoi(int n, int s, int f){
	if(n == 1){
		printf("%d %d\n", s, f);
		return ;
	}

	int x = 0;
	switch(s+f){
		case 3:
			x = 3;
			break;
		case 4:
			x = 2;
			break;
		case 5:
			x = 1;
			break;
	}
	solve_hanoi(n-1, s, x);
	printf("%d %d\n", s, f);
	solve_hanoi(n-1, x, f);
}

int main(){
	int arr[2] = { 0, };
	int n = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		arr[(i+1)%2] = 2*arr[i%2]+1;
	}

	printf("%d\n", arr[n%2]);
	solve_hanoi(n, 1, 3);

	return 0;
}
