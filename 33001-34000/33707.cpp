#include <cstdio>

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

	for(int y = 0; y < r; y ++){
		for(
			int x = 1 - (y&1); x < c; x +=2
		){
			if(query(y+1, x+1) == 1) return 0;
		}
	}
	return 0;
}
