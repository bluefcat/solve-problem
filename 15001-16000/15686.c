#include <stdio.h>

#define ABS(X) ((X) > 0? (X): -(X))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define INF 2501

int hpos[101][2];
int hlen;
int cpos[14][2];
int clen;

int comb[14];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			int tmp = 0;
			scanf("%d", &tmp);
			
			if(tmp == 1){
				hpos[hlen][0] = i; hpos[hlen][1] = j;
				hlen ++;
			}

			if(tmp == 2){
				cpos[clen][0] = i; cpos[clen][1] = j;
				clen ++;
			}
		}
	}
	return 0;
}


