#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){ return *(int*)x - *(int*)y; }

int main(){
	int result[7] = { 0, };
	int cache[9] = { 0, };

	for(int i = 0; i < 9; i ++) scanf("%d", cache+i);

	int idx = 0;

	while(idx <= (1 << 9)){
		for(int i = 0; i < 7; i ++) result[i] = 0;
		int sum = 0;

		if(__builtin_popcount(idx) == 7){
			
			int tmp = 1, cnt = 0;
			for(int i = 0; i < 9; i ++){
				if(idx & tmp){
					sum += cache[i];
					result[cnt++] = cache[i];
				}
				tmp <<= 1;
			}
			
			if(sum == 100){
				break;
			}

		}
		idx ++;
	}
	
	qsort(result, 7, sizeof(int), compare);

	for(int i = 0; i < 7; i ++) printf("%d\n", result[i]);

	return 0;
}
