#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
int length(const char* str){
	int result = 0;
	while(*(str++)) result ++;
	return result;
}

int main(){
	int result = 0;
	char A[51] = { 0, };
	char B[51] = { 0, };

	scanf("%s %s", A, B);
	
	result = length(A);
	for(int offset = 0; offset <= length(B) - length(A); offset ++){
		int tmp = 0;
		for(int idx = 0; idx < length(A); idx ++){
			tmp += (int)(A[idx] != B[idx + offset]);
		}
		
		result = MIN(result, tmp);
	}

	printf("%d\n", result);

	return 0;
}
