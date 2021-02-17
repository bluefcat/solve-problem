#include <stdio.h>

char wear[31][2][21];

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i ++){
		int n, result = 0;
		scanf("%d", &n);
		
		for(int j = 0; j < n; j ++){
			scanf("%s", wear[j][0]);
			scanf("%s", wear[j][1]);
		}
		

		printf("%d\n", result); 
	}

	return 0;
}
