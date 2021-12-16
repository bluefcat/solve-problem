#include <stdio.h>

int is_croatia(char* p){
	int result = 1;

	char alpha[12][3] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=", "l", "n", "s", "z"};
	int cand[12] = { 0, };

	for(int i = 0; i < 12; i ++) cand[i] = 1;

	int idx = 0;
	while(1){
		for(int i = 0; i < 12; i ++){
			if(cand[i] == 0) continue;
			cand[i] = (int)(alpha[i][idx] == *(p+idx));
		}

		idx ++;
		
		int cnt = 0;
		for(int i = 0; i < 12; i ++) cnt += cand[i];
		
		if(cnt <= 1 || idx > 2){
			if(cnt == 1) result += idx;
			break;
		}
	}

	return result;
}

int main(){
	int result = 0;
	char string[101] = { 0, };

	scanf("%s", string);

	char* p = string;
	
	while(*p){
		int next = is_croatia(p);
		result ++;
		p += next;
	}

	printf("%d\n", result);

	return 0;
}
