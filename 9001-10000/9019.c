#include <stdio.h>


int D(int reg){
	reg = (reg << 1) % 10000;
	return reg;
}

int S(int reg){
	reg = reg > 1? reg-1: 9999;
	return reg;
}

int L(int reg){
	int tmp = reg;
	int n[4] = { 0, };
	
	for(int i = 0; i < 4; i ++){
		n[3-i] = tmp % 10; tmp /= 10;
	}
	
	tmp = n[0];

	for(int i = 0; i < 3; i ++){
		n[i] = n[i+1];
	}
	n[3] = tmp;
	
	reg = ((n[0] * 10 + n[1]) * 10 + n[2]) * 10 + n[3];
	return reg;
}
int R(int reg){
	int tmp = reg;
	int n[4] = { 0, };
	
	for(int i = 0; i < 4; i ++){
		n[3-i] = tmp % 10; tmp /= 10;
	}

	tmp = n[3];

	for(int i = 3; i >= 1; i --){
		n[i] = n[i-1];
	}
	n[0] = tmp;
	
	reg = ((n[0] * 10 + n[1]) * 10 + n[2]) * 10 + n[3];
	return reg;
}

#define SMAX 1001
int sint[SMAX];
char schar[SMAX];
int head;
int flag;

int r, t;

int (*fp[4])(int) = { D, S, L, R };
char name[4] = { 'D', 'S', 'L', 'R' };

void solve(int reg, int tar, int d){
		
	return ;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		flag = 0;
		head = 0;
		for(int i = 0; i < SMAX; i ++){
			schar[i] = 0;
		}

		scanf("%d %d", &r, &t);
		
		solve(r, t, 0);

		printf("%s\n", schar);
	}
	
	return 0;
}
