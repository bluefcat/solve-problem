#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char names[100001][21];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++) scanf("%s", names[i]);
	
	for(int i = 0; i < m; i ++){
		char problem[21] = { 0, };
		scanf("%s", problem);

		int x = atoi(problem);

		if(x){
			printf("%s\n", names[x-1]);
		}
		else{ //if atoi is not worked, returns 0
			for(int j = 0; j < n; j ++){
				if(strcmp(names[j], problem) == 0){
					printf("%d\n", j+1);
					break;
				}
			}
		}
	}



	return 0;
}
