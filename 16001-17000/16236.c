#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

#define QSIZE 21*21

//x, y, size, second
int queue[QSIZE][4]; 
int head, tail;

int map[21][21];
int n, result;

int dx[] = {};
int dy[] = {};

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) scanf("%d", map[i]+j);
	}



	return 0;
}


