#include <stdio.h>

typedef struct match_{
	long long key;
	int idx;
} match;

match bucket[100001];
int count[100001]; 
int head;

long long result[2];

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		long long tmp;
		scanf("%lld", &tmp);

		int n = 0;
		for(;n < head; n ++){
			if(bucket[n].key == tmp) break;
		}

		if(n == head){
			bucket[head].key = tmp;
			bucket[head].idx = head;
			count[head] ++;

			head ++;
			goto REFLESH;
		}

		count[bucket[n].idx] ++;

		REFLESH:
		
		if((result[1] < count[bucket[n].idx]) ||
		   (result[0] > tmp && result[1] == count[bucket[n].idx])){
			result[0] = tmp;
			result[1] = count[bucket[n].idx];
		}


	}

	printf("%lld\n", result[0]);

	return 0;
}
