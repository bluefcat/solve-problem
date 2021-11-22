#include <stdio.h>
#include <stdlib.h>

int m, n, k;

int paper[101][101];
int isgo[101][101];

int area_length;
int area[10201];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

void count_area(int x, int y){
	if(paper[x][y] == 1) return;
	isgo[x][y] = 1;
	area[area_length] ++;

	int dx[] = {  0,  1,  0, -1 };	
	int dy[] = {  1,  0, -1,  0 };

	for(int i = 0; i < 4; i ++){
		if(0 > x+dx[i] || x+dx[i] >= n) continue;
		if(0 > y+dy[i] || y+dy[i] >= m) continue;
		
		if(isgo[x + dx[i]][y + dy[i]] == 0) count_area(x + dx[i], y + dy[i]);
	}
}

int main(){
	scanf("%d %d %d", &m, &n, &k);

	for(int i = 0; i < k; i ++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for(int x = x1; x < x2; x ++){
			for(int y = y1; y < y2; y ++){
				paper[x][y] = 1;
			}
		}
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(paper[i][j] || isgo[i][j]) continue;
			count_area(i, j);
			area_length ++;
		}
	}
	
	qsort(area, area_length, sizeof(int), compare);
	
	printf("%d\n", area_length);
	for(int i = 0; i < area_length; i ++){
		printf("%d ", area[i]);
	}

	printf("\n");

	return 0;
}
