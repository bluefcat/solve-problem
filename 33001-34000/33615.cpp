#include <cstdio>

constexpr int N = 500001;

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		char tmp[N] = { 0, };
		scanf("%s", tmp);
		int op = -1, fp = -1, s = 0;
		char* p = tmp;
		int i = 0;
		for(i = 0; tmp[i]; i ++){
			op = (tmp[i] == '1')?(i+1):op;
			fp = (tmp[i] == '5')?(i+1):fp;
			s += (tmp[i] - '0');
		}
		
		if(tmp[i-1] == '5'){
			printf("0 5\n");
		}
		else if(s % 3 == 0){
			printf("0 3\n");
		}
		else if(s % 3 == 2 && fp != -1){
			printf("%d 3\n", fp);
		}
		else if(s % 3 == 1 && op != -1){
			printf("%d 3\n", op);
		}
		else if(s % 3 == 2 && fp == -1){
			printf("%d 11\n", op);
		}
		else {
			printf("0 11\n");
		}

	}
}
