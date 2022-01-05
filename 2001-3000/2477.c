#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int result = 0;

	int pattern[4][4] = {
		{1, 4, 1, 4},
		{4, 2, 4, 2},
		{3, 1, 3, 1},
		{2, 3, 2, 3}
	};

	int rotate[6] = { 0, };
	int length[6] = { 0, };

	for(int i = 0; i < 6; i ++){
		scanf("%d %d", rotate+i, length+i);
	}

	

	return 0;
}
