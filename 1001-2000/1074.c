#include <stdio.h>

int flag, r, c;
long long count, result;

void solve(int x0, int y0, int x1, int y1){
	if(flag) return;
	if(x0 == (x1-1) && y0 == (y1-1)){
		count ++;
		if(c == x0 && r == y0){
			result = count - 1;
			flag = 1;
		}
		return;
	}

	int xm = (x0 + x1) >> 1;
	int ym = (y0 + y1) >> 1;
	
	if((x0 <= c && c <= x1) && (y0 <= r && r <= y1)){
		solve(x0, y0, xm, ym);
		solve(xm, y0, x1, ym);
		solve(x0, ym, xm, y1);
		solve(xm, ym, x1, y1);
	}
	else 
		count += (x1-x0) * (y1-y0);
	return;
}

int main(){
	int n = 0;
	scanf("%d %d %d", &n, &r, &c);
	
	solve(0, 0, 1 << n, 1 << n);

	printf("%lld\n", result);
	return 0;
}
