#include <stdio.h>
#include <limits.h>

long long numbers[12];
int n, oper[4];
long long tmp = 0;
long long maxr = LLONG_MIN;
long long minr = LLONG_MAX;

long long add(long long x, long long y){
	return x+y;
}

long long sub(long long x, long long y){
	return x-y;
}

long long mul(long long x, long long y){
	return x*y;
}

long long div(long long x, long long y){
	return x/y;
}

long long (*fp[4])(long long, long long);

void insertion(int x){
/*
 	the arguement x is index of array "numbers"
 */	
	if(x == n){
		if(maxr < tmp) maxr = tmp;
		if(minr > tmp) minr = tmp;
		return;
	}
	//operation collect
	for(int i = 0; i < 4; i ++){
		if(oper[i] == 0) continue;
		
		oper[i] --;
		int ttmp = tmp;
		tmp = fp[i](tmp, numbers[x]);

		insertion(x+1);

		oper[i] ++;
		//div isn't revesiable
		tmp = ttmp;
	}

	return ;
}

int main(){
	fp[0] = add; fp[1] = sub; fp[2] = mul; fp[3] = div;

	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%lld", numbers+i);
	}
	scanf("%d %d %d %d", oper+0, oper+1, oper+2, oper+3);
	
	tmp = numbers[0];
	insertion(1);
	
	printf("%lld\n%lld\n", maxr, minr);
	return 0;
}
