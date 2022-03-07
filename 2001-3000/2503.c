#include <stdio.h>

int game[10][3];

int main(){
	int t = 0;
	
	scanf("%d", &t);

	while(t--){
		char q[3];
		int s, b;

		scanf(" %3c %d %d", q, &s, &b);
			
		for(int i = 0; i < 3; i ++) game[q[i] - '0'][i] += s * 10 + b;
		
		for(int i = 1; i < 10; i ++) printf("[%d]: %2d %2d %2d\n", i, game[i][0], game[i][1], game[i][2]);
	}


	return 0;
}
