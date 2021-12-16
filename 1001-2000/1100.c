#include <stdio.h>

char board[8][8];

int main(){
	int result = 0;
	for(int i = 0; i < 8; i ++){
		if(i != 0) scanf(" ");
		for(int j = 0; j < 8; j ++) scanf("%c", board[i]+j);
	}

	for(int i = 0; i < 8; i ++){
		for(int j = 0; j < 8; j ++){
			if((i & 1) == (j & 1)){
				result += (int)(board[i][j] == 'F');
			}

		}
	}

	
	printf("%d\n", result);
	return 0;
}
