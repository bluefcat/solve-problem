#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)x < *(int*)y;
}

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i ++){
		int queue[101];
		int order[101];
		int n, m, result = 0;
		scanf("%d %d", &n, &m);
		
		for(int j = 0; j < n; j ++){
			scanf("%d", queue+j);
			order[j] = queue[j];
		}

		qsort(order, n, sizeof(int), compare);

		int start = 0, cur = 0;
		for(int i = 0; i < n; i ++){
			do{
				if(queue[cur] == order[i]){
					result ++;
					if(cur == m) goto RESULT;
					cur = (cur+1) % n;
					break;
				} 
				cur = (cur+1) % n;
			}while(start != cur);
			start = cur;
		}

		RESULT:
		printf("%d\n", result);
	}

	return 0;
}
