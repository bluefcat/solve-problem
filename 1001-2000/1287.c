#include <stdio.h>

#define START	0x01

#define DIGIT	0x02
#define NUMBER	0x04
#define EXPR	0x08

#define ACCEPT	0xF0
#define DENINE	0xFF

const char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const char expr[] = {'+', '-', '*', '/', '(', ')'};

const unsigned char end = 0xFF;

int is_digit(const char word){
	int length = sizeof(digit)/sizeof(const char);

	for(int i = 0; i < length; i ++){
		if(digit[i] == word) return i;
	}

	return -1;
}

int is_expr(const char word){
	int length = sizeof(expr)/sizeof(const char);

	for(int i = 0; i < length; i ++){
		if(expr[i] == word) return i;
	}

	return -1;
}

typedef struct{
	int x;
	int result;
	unsigned char mode;
} Result;

Result parse(const char* string, int i, Result pack){
	switch(pack.mode){
		case START:
			if(is_digit(string[i]) != -1){
				pack.mode = NUMBER;
				return parse(string, i, pack);
			}
			else if(string[i] == '('){
				pack.mode = EXPR;
				return parse(string, i, pack);
			}
			else{
				pack.mode = DENINE;
				return parse(string, i, pack);
			}
			break;

		case DIGIT:
			break;

		case NUMBER:
			const char x = string[i];
			const char y = string[i+1];
			if(is_digit(y) == -1){
				return parse(string, i+1, pack);
			}
			else{
				return parse(string, i+1, pack);
			}

			break;
		
		case EXPR:
			break;


		case ACCEPT:
		case DENINE:
		default:
			return pack;
	}
}

int main(){
	Result result;
	result.mode = START;
	printf("%d\n", parse("*", 0, result).mode);
	return 0;
}
