#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, result = 64;
	char** board;

	scanf("%d %d", &n, &m);
	
	board = (char**)malloc(sizeof(char*)*n);
	board[0] = (char*)malloc(sizeof(char)*n*m);
	for(int i = 1; i < n; i ++){
		board[i] = board[i-1]+m;
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			scanf(" %c", board[i]+j);
		}
	}
	
	for(int i = 0; i < n-7; i ++){
		for(int j = 0; j < m-7; j ++){
			//first block is W or B
			for(int c = 0; c < 2; c ++){	
				int result_temp = 0;
				char temp = (c == 0)? 'W': 'B';

				for(int x = i; x < 8+i; x ++){
					for(int y = j; y < 8+j; y ++){
						if(temp != board[x][y]){
							result_temp ++;
						}
						temp = (y == 7+j)? temp: (temp == 'W')? 'B': 'W';
					}
				}
				if(result > result_temp) result = result_temp;
			}
		}
	}

	printf("%d\n", result);

	free(board[0]);
	free(board);
	return 0;
}
