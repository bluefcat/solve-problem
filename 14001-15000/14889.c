#include <stdio.h>
#include <limits.h>

int n, member[21][21];
int check[21] = { 0, };
int check_n = 0;
int diff = INT_MAX;

int abs(int x){
	return (x > 0)? x: -x;
}

void battle_team(int x, int y){
	if(x > n/2) return;
	if(y > n/2) return;

	if(x == n/2 && y == n/2){
		int a = 0, b = 0;
		for(int i = 0; i < n; i ++){
			for(int j = i; j < n; j ++){
				if(check[i] == 0 && check[j] == 0){
				   	a += member[i][j]+member[j][i];
					
				}
				if(check[i] == 1 && check[j] == 1){
				   	b += member[i][j]+member[j][i];
				}
			}
		}

		if(diff > abs(a-b)) diff = abs(a-b);
		return;
	}

	for(int i = 0; i < 2; i ++){
		check[x+y] = i;
		if(i == 0){
			battle_team(x+1, y);
		}
		else{
			battle_team(x, y+1);
		}
	}

	return ;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
		   	scanf("%d", member[i]+j);
		}
	}
	
	battle_team(0, 0);

	printf("%d\n", diff);
	return 0;
}
