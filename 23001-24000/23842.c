#include <stdio.h>

int match[10] = {
  //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	6, 2, 5, 5, 4, 5, 6, 3, 7, 6 
};

int formula[7] = { 0, };

int main(){
	int n; 
	scanf("%d", &n);

	n -= 4;

	int idx = 0;
	while(formula[7] != 1){
		int x = formula[0] * 10 + formula[1];
		int y = formula[2] * 10 + formula[3];
		int z = formula[4] * 10 + formula[5];

		if(x + y == z){
			int m = 0;
			for(int i = 0; i < 6; i ++) m += match[formula[i]];

			if(m == n){
				printf("%d%d+%d%d=%d%d\n",
						formula[0], formula[1],
						formula[2], formula[3],
						formula[4], formula[5]
					  );

				return 0;
			}
		}


		//increase
		int tmp = idx;
		formula[tmp] ++;
		
		while(formula[tmp] == 10){
			formula[tmp++] = 0;
			formula[tmp] += 1;
		}
	}
	
	printf("impossible\n");

	return 0;
}
