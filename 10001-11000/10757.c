#include <stdio.h>
#include <string.h>

#define MAX(X, Y) ((X)>(Y)? (X): (Y))
#define M 10001

int main(){
	char a[M] = { 0, };
	char b[M] = { 0, };
	char c[M+1] = { 0, };

	scanf("%s %s", a, b);

	//long context, short context
	char *p_long = a, *p_short= b;
	int len_long = strlen(a), len_short = strlen(b);
	
	//swap
	if(len_long < len_short){
		char* p_tmp = p_long; p_long = p_short; p_short = p_tmp;
		int len_tmp = len_long; len_long = len_short; len_short = len_tmp;
	}

	int idx_sum = 0;
	
	int idx_long = len_long-1, idx_short= len_short-1;

	int n_sum = 0;
	int carry = 0;
	while(idx_long >= 0){
		int n_long = p_long[idx_long] - '0';	
		int n_short = (idx_short >= 0)? (p_short[idx_short] - '0'): 0;
		
		n_sum = (n_long + n_short + carry) % 10;
		carry = (n_long + n_short + carry) / 10;
		
		c[idx_long+1] += n_sum;
		
		idx_long -= 1;
		idx_short -= 1;

		idx_sum ++;
		if(idx_long < 0 && carry != 0) idx_sum ++;
	}
	c[0] = carry;

	if(c[0] == 0){
		for(int i = 0; i <= idx_sum; i ++) c[i-1] = c[i];
	}

	for(int i = 0; i < idx_sum; i ++){
		printf("%d", c[i]);
	}
	printf("\n");

	return 0;
}
