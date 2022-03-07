#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cache[100005];
int stack[100005];
int head;

int main(){
	int n;
	while(scanf("%d", &n) && n!= 0){
		for(int i = 0; i < n; i ++) scanf("%d", cache+i);
		
		long long result = 0;
		long long width = 0;
		long long height = 0;

		head = 0;

		for(int i = 0; i <= n ; i ++){
			while(head){
				if(i != n && cache[stack[head-1]] <= cache[i]) break;

				height = cache[stack[--head]];
				width = i;

				if(head) width = i - stack[head-1] - 1;
				
				result = MAX(result, (width * height));
			}

			if(i != n) stack[head++] = i;
		}
		printf("%lld\n", result);
	}

}
