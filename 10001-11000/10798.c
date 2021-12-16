#include<stdio.h>

int main(){
	char string[5][15] = { 0, };

	for(int i = 0; i < 5; i ++){
		int j = 0;
		while(scanf("%c", string[i]+j) && string[i][j++] != '\n');
		string[i][j-1] = 0;
	}
	
	for(int j = 0; j < 15; j ++){
		for(int i = 0; i < 5; i ++){
			if(string[i][j]) printf("%c", string[i][j]);

		}
	}

	printf("\n");
	return 0;
}
