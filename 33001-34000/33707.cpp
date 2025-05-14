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
			int x = 0; x < c; x ++
		){
			//printf("%c", (x%2 == (y&1))?'.':'#');
			if(x%2 != (y&1)) if(query(y+1, x+1) == 1) return 0;
		}
		//printf("\n");
	}
	return 0;
}
