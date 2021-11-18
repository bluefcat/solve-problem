#include <stdio.h>

int main(){
	int eq_flag = 1, iso_flag = 0;
	int angle = 0;
	int angles[3] = { 0, };

	for(int i = 0; i < 3; i ++){
		scanf("%d", angles + i);
		angle += angles[i];
		if(angles[i] != 60) eq_flag = 0;
	}

	for(int i = 0; i < 2; i ++){
		for(int j = 0; j < 3; j ++){
			if(i == j) continue;
			if(angles[i] == angles[j]) iso_flag = 1;
		}
	}

	if(angle != 180){
		printf("Error\n");
		return 0;
	}

	if(eq_flag){
		printf("Equilateral\n");
	}
	else if(iso_flag){
		printf("Isosceles\n");
	}
	else{
		printf("Scalene\n");
	}

	return 0;
}
