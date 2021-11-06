#include <stdio.h>

int main(){
	int T, cache[100001][2] = { 0, };
	
	scanf("%d", &T);

	while(T--){
		int n = 0, result = 0;
		scanf("%d", &n);

		for(int i = 0; i < n; i ++) scanf("%d %d", cache[i], cache[i]+1);

		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				if(cache[i][0] < cache[j][0] && cache[i][1] < cache[j][1]){
					break;
				}
				else{
					result ++;
					break;
				}
			}
		}
		
		printf("[%d]\n", result);
		
	}


	return 0;
}
