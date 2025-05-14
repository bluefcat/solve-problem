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
	int t = r-1;
	int sy = (t/2)*2, sx = 0;
	int f = 0;
	while(query(sy+1, sx+1) != 1){
		sy ++, sx ++;
		if(sy >= r || sx >= c){
			t = std::max(0, t-2);
			sy = (t/2)*2, sx = 0;
			if(f){
				sx += 2*f;
			}
			if(sy == 0) f ++;	
		}
	}


	return 0;
}
