#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	
	while(T--){
		int n, result = 0;
		scanf("%d", &n);

		for(int x = 1; x < n; x ++){
			for(int y = 1; y < n; y ++){
				for(int z = 1; z < n; z ++){
					if(x*(x+1) + y*(y+1) + z*(z+1) == n<<1) {
						result = 1;
						goto END;
					}
				}
			}
		}
		END:
		printf("%d\n", result);
	}
	return 0;
}
