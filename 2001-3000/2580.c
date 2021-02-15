#include <stdio.h>

int board[9][9];
int min_check[9] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
int max_check[9] = { 3, 3, 3, 6, 6, 6, 9, 9, 9 };
int match = 0;

void sudoku(int n){
	if(n >= 81){
		match = 1;
		return ;
	}

	int x = n/9, y = n%9;
	if(board[x][y]){
		sudoku(n+1);
		return ;
	}

	for(int p = 0; p < 9; p ++){
		int flag = 0;
		//check row
		for(int i = 0; i < 9; i ++){
			if(i == x) continue;
			if(board[i][y] == p+1) flag = 1;
		}

		//check col
		for(int i = 0; i < 9 ; i ++){
			if(i == y) continue;
			if(board[x][i] == p+1) flag = 1;
		}

		//check block
		for(int i = min_check[x]; i < max_check[x]; i ++){
			for(int j = min_check[y]; j < max_check[y]; j ++){
				if(i == x && j == y) continue;
				if(board[i][j] == p+1) flag = 1;
			}
		}
		//branch
		if(!flag){
			board[x][y] = p+1;
			sudoku(n+1);
			if(match == 1) return;
			board[x][y] = 0;
		}
	}

	return ;
}

int main(){
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j ++){
			scanf("%d", board[i]+j);
		}
	}

	sudoku(0);

	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j ++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}
