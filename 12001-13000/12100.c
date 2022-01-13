#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[21][21];
int n;
int result;

void up(){
	for(int y = 0; y < n; y ++){
		
		int last = 0;
		for(int x = 1; x < n; x ++){
			if(map[x][y] == 0) continue;
			
			if(map[last][y]){
				if(map[last][y] == map[x][y]){
					map[last][y] += map[x][y];
					map[x][y] = 0;
					last ++;
				}
				else{
					map[++last][y] = map[x][y];
					if(last != x) map[x][y] = 0;
				}
			}
			else{
				map[last][y] = map[x][y];
				map[x][y] = 0;
			}
		}
	}
}

void down(){
	for(int y = 0; y < n; y ++){

		int last = n-1;
		for(int x = n-2; x >= 0; x --){
			if(map[x][y] == 0) continue;
			
			if(map[last][y]){
				if(map[last][y] == map[x][y]){
					map[last][y] += map[x][y];
					map[x][y] = 0;
					last --;
				}
				else{
					map[--last][y] = map[x][y];
					if(last != x) map[x][y] = 0;
				}
			}
			else{
				map[last][y] = map[x][y];
				map[x][y] = 0;
			}
		}
	}
}

void left(){
	for(int x = 0; x < n; x ++){
		
		int last = 0;
		for(int y = 1; y < n; y ++){
			if(map[x][y] == 0) continue;
			
			if(map[x][last]){
				if(map[x][last] == map[x][y]){
					map[x][last] += map[x][y];
					map[x][y] = 0;
					last ++;
				}
				else{
					map[x][++last] = map[x][y];
					if(last != y) map[x][y] = 0;
				}
			}
			else{
				map[x][last] = map[x][y];
				map[x][y] = 0;
			}
		}
	}
}

void right(){
	for(int x = 0; x < n; x ++){

		int last = n-1;
		for(int y = n-2; y >= 0; y --){
			if(map[x][y] == 0) continue;
			
			if(map[x][last]){
				if(map[x][last] == map[x][y]){
					map[x][last] += map[x][y];
					map[x][y] = 0;
					last --;
				}
				else{
					map[x][--last] = map[x][y];
					if(last != y) map[x][y] = 0;
				}
			}
			else{
				map[x][last] = map[x][y];
				map[x][y] = 0;
			}
		}
	}
}

void print(){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void solution(int d){
	if(d == 5){
		int tmp = 0;
		for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) tmp = MAX(tmp, map[i][j]);
		result = MAX(result, tmp);
		return;
	}

	int arr[21][21];

	for(int i = 0; i < 21; i ++) for(int j = 0; j < 21; j ++) arr[i][j] = map[i][j];

	void(*f[4])() = {up, down, left, right};

	for(int i = 0; i < 4; i ++){
		for(int i = 0; i < 21; i ++) for(int j = 0; j < 21; j ++) map[i][j] = arr[i][j];
		f[i]();
		solution(d+1);
	}

	return;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) scanf("%d", map[i] + j);
	}

	solution(0);
	printf("%d\n", result);
	return 0;
}
