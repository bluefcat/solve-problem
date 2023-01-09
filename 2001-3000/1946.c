#include <stdio.h>

int main(){
	int T;
	int ARR[100001][2] = { 0, };
	scanf("%d", &T);

	while(T--){
		int result = 0;
		int N;
		
		scanf("%d", &N);

		for(int i = 0; i < N; i ++){
			scanf("%d %d", ARR[i]+0, ARR[i]+1);
		}
		
		int tmp[100][100] = { 0, };
		for(int i = 0; i < N; i ++){
			for(int j = 0; j < N; j ++){
				tmp[i][j] = 1;
				if(ARR[i][0] < ARR[j][0] && ARR[i][1] < ARR[j][1]) tmp[i][j] = 0;
			}
		}

		for(int i = 0; i < N; i ++){ for(int j = 0; j < N; j ++) printf("%d\t", tmp[i][j]); printf("\n");}
	}


	return 0;
}
