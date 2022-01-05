#include <stdio.h>

int main(){
	char score[6] = { 4, 3, 2, 1, 0, 0 };
	char a, b;
	
	scanf("%c%c", &a, &b);

	printf("%.1lf\n", 
			(float)(
				score[a-'A'] + ( b == '+'? 0.3: (b=='-'? -0.3:0 ) )

			)
	);

	return 0;
}
