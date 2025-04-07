#include <cstdio>
#include <algorithm>

constexpr int N = 52;
constexpr int H = 500001;

int block[N];
int count[N];
int height[N][H][N]; 

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i ++){
		scanf("%d", block+i);
		count[block[i]] ++;
	}
	height[0][0][0] = 1;
	
	for(int b = 1; b <= n; b ++){
		for(int h = 0; h < H; h ++){
			height[b][h][0] = height[b-1][h][0];
			for(int i = 1; i <= n; i ++)
				height[b][h][i] += height[b-1][h][i];

			if(h >= block[b]){
				height[b][h][0] += height[b-1][h-block[b]][0];
				if(height[b-1][h-block[b]][0] != 0){
					for(int i = 1; i <= n; i ++)
						height[b][h][i] += height[b-1][h-block[b]][i];
					height[b][h][b] ++;
				}
			}		
		}
	}

	int result = -1;
	for(int h = 0; h < H; h +=2){
		if(height[n][h][0] >= 1 && height[n][h/2][0] >= 2){
			for(int b = 1; b <= n; b ++){
				if(count[b] < (height[n][h/2][b] / height[n][h/2][0])) goto NEXT;
			}

			result = h/2;
		}
		NEXT:
		continue;
	}
	printf("%d\n", result);
	
	return 0;
}
