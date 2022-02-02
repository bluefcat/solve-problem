#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ram[100001];
int reg[10];

int length;

int oper[3];
int pc;
int count;
int is_halt;

void get_operator(int*, int*);
void interprete(int*);
int contain_zero(int);

void print(){
	for(int i = 0; i < length; i ++){
		printf("[%02d] ", i);
		if(i == pc) printf(">\t");
		else printf(" \t");

		printf("[%03d]\n", ram[i]);
	}

	printf("[%02d/%3d]\n====REG====\n", pc, count);
	for(int i = 0; i < 10; i ++){
		printf("[%d](%d) ", i, reg[i]);
	}
	printf("\n===========\n");
	
	sleep(2);
	system("clear");
	return;
}

int main(){
	while(scanf("%d", ram+(length++)) != EOF);
	
	//system("clear");

	while(!is_halt){
		get_operator(ram+pc, oper);
		interprete(oper);
	}
	printf("%d\n", count);
	return 0;
}

void get_operator(int* ram, int* oper){
	int tmp = *ram;
	for(int i = 0; i < 3; i ++){
		oper[i] = tmp%10;
		tmp /= 10;
	}
	
	tmp = oper[0]; oper[0] = oper[2]; oper[2] = tmp;
	return;
}

void interprete(int* oper){
	count ++;
	if(oper[0] == 1 && oper[1] == 0 && oper[2] == 0){
		is_halt = 1;
		return;
	}
	
	int d = 0, n = 0, s = 0, a = 0;

	switch(oper[0]){
		case 2:
			d = oper[1], n = oper[2];
			reg[d] = n;
			reg[d] %= 1000;
			break;
		case 3:
			d = oper[1], n = oper[2];
			reg[d] += n;
			reg[d] %= 1000;
			break;
		case 4:
			d = oper[1], n = oper[2];
			reg[d] *= n;
			reg[d] %= 1000;
			break;
		case 5:
			d = oper[1], s = oper[2];
			reg[d] = reg[s];
			reg[d] %= 1000;
			break;
		case 6:
			d = oper[1], s = oper[2];
			reg[d] += reg[s];
			reg[d] %= 1000;
			break;
		case 7:
			d = oper[1], s = oper[2];
			reg[d] *= reg[s];
			reg[d] %= 1000;
			break;
		case 8:
			d = oper[1], a = oper[2];
			reg[d] = ram[reg[a]];
			reg[d] %= 1000;
			break;
		case 9:
			s = oper[1], a = oper[2];
			ram[reg[a]] = reg[s];
			break;
		case 0:
			d = oper[1], s = oper[2];
			
			if(!contain_zero(reg[s])) pc = reg[d];
			else pc ++;
			return;
	}

	pc ++;
}

int contain_zero(int x){
	if(x == 0) return 1;
	while(x > 0){
		if(x % 10 == 0) return 1;
		x /= 10;
	}
	return 0;
}
