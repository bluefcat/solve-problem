#include <stdio.h>
#define MAX_SCORE 10000
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int main(){
	int score_count[MAX_SCORE+1] = { 0, };
	
	int max = 0;
	int N, k;
	scanf("%d %d", &N, &k);

	for(int i = 0; i < N; i ++){
		int score = 0;
		scanf("%d", &score);
		max = MAX(max, score);
		score_count[score] ++;
	}
	
	int result = max;
	int count = 0;
	for(int score = max; score >= 0; score --){
		count += score_count[score];

		if(count >= k){
			result = score;
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}
