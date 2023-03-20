#include <stdio.h>

int main(){
	int origin[] = {1, 1, 2, 2, 2, 8};
	int result[] =  {0, 0, 0, 0, 0, 0};

	for(int i = 0; i < 6; i ++){
		int x = 0;
		scanf("%d", &x);

		result[i] = origin[i] - x;
	}

	for(int i = 0; i < 6; i ++) printf("%d ", result[i]);
	printf("\n");
	return 0;
}
