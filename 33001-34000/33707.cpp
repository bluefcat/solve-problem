#include <cstdio>
#include <algorithm>

int query(int r, int c){
	printf("? %d %d\n", r, c);
	fflush(stdin);
	int result = 0;
	scanf("%d", &result);
	return result;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	int idx = (r & 1) && (c & 1);
	int y = idx / c, x = idx % c;
	while(query(y+1, x+1) != 1){
		idx += 2;
		y = idx / c, x = idx % c;
	}

	return 0;
}
