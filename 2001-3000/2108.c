#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAXINDEX 8001
#define TOINDEX(X) ((X)+4000)
#define UNINDEX(X) ((X)-4000)

int main(){
	int mean, median, mode, range;
	int min = INT_MAX, max = INT_MIN, max_mode = 0;
	double sum = 0;
	int n;
	int bucket[MAXINDEX] = { 0, };

	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int tmp;
		scanf("%d", &tmp);
		bucket[TOINDEX(tmp)] ++;

		if(min > tmp) min = tmp;
		if(max < tmp) max = tmp;

		if(max_mode < bucket[TOINDEX(tmp)]) max_mode = bucket[TOINDEX(tmp)];
		
		sum += tmp;
	}

	//mean
	mean = (int)round(sum/n);
	//median
	int cnt = 0;
	for(int i = TOINDEX(min); i <= TOINDEX(max); i ++){
		cnt += bucket[i];
		median = UNINDEX(i);
		if(cnt > n/2) break;
	}
	//range
	range = max - min;
	//mode
	int flag = 0;
	for(int i = TOINDEX(min); i <= TOINDEX(max); i ++){
		if(bucket[i] == max_mode && !flag){
			mode = UNINDEX(i);
			flag = 1;
		}
		else if(bucket[i] == max_mode){
			mode = UNINDEX(i);
			break;
		}
	}

	printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
	return 0;
}
