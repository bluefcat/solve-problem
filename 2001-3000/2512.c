#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int budgets[100001];

int main(){
	int t, n, m = 0;
	int result = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", budgets + i);
		m = MAX(m, budgets[i]);
	}
	
	scanf("%d", &t);

	int s = 0, e = m;
	

	while(s <= e){
		int mid = (s+e) >> 1;
		
		int total = 0;
		int cm = 0;
		for(int i = 0; i < n; i ++){
			total += MIN(mid, budgets[i]);
			cm = MAX(cm, MIN(mid, budgets[i]));
		}
		
		if(total <= t){
			result = MAX(cm, result);
			s = mid+1;
		}
		else{
			e = mid-1;
		}

	}

	printf("%d\n", result);
	return 0;
}
