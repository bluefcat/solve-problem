#include <stdio.h>
#include <math.h>

int main(){
	int min = 0, max = 0;
	int m, n;
	scanf("%d\n%d", &m, &n);
	
	for(int i = m; i <= n; i ++){
		//if not square number break;
		switch(i & 0x0f){
			case 0:
			case 1:
			case 4:
			case 9:
			{	
				unsigned int t = (unsigned int)(sqrt((double)i) + 0.5);
				if(t*t != i) break;

				if(min == 0) min = i;
				max += i;
				break;
			}
			default:
			break;
		}
	}
	
	if(min != 0) printf("%d\n%d\n", max, min);
	else printf("-1\n");

	return 0;
}
