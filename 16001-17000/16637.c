#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))


int n;
char formula[20];
char visited[20];
int result = 0;

int solve(char oper, int x, int y){
	int t;

	switch(oper){
		case '+':
			t = x + y;
			break;
		case '-':
			t = x - y;
			break;
		case '*':
			t = x * y;
			break;
	}
	return t;
}

int main(){
	scanf("%d", &n);
	
	scanf("%s", formula);

	for(int i = 1; i < (n >> 1)+1; i ++){
		int x = solve(formula[2*i-1], formula[2*i-2] -'0', formula[2*i] - '0');
		printf("%d\n", x);
	}

	printf("%d\n", result);
	return 0;
}
