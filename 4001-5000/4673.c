#include <stdio.h>

int self_number[10001];

int d(int n){
	int result = n;
	
	while(n != 0){
		result += n % 10;
		n = n / 10;
	}

	return result;
}

int main(){
	for(int i = 0; i < 10001; i ++) self_number[i] = 0;

	for(int i = 1; i < 10001; i ++){
		int k = i;
		if(self_number[k] == 1) continue;

		while(k < 10001){
			k = d(k);
			self_number[k] = 1;
		}
	}

	for(int i = 1; i < 10001; i ++){
		if(!self_number[i]) printf("%d\n", i);
	}

	return 0;
}
