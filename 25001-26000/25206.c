#include <stdio.h>
#define MAX 20

int main(){
	char name[51] = { 0, };
	double unit[MAX];
	char score[MAX][3];

	for(int i = 0; i < 20; i ++){
		scanf("%s %lf %s", name, unit+i, score[i]);
	}

	double result = 0.0;
	double sum = 0.0;
	
	for(int i = 0; i < 20; i ++){
		double s = (double)(4.0 + ('A' - score[i][0]));
		if(score[i][1] == '+') s += 0.5;

		
		if(score[i][0] == 'P' ||
		   score[i][0] == 'F' ){
			s = 0.0;
		}
		
		if(score[i][0] == 'P') sum -= unit[i];

		result += s * unit[i];
		sum += unit[i];
	}

	if(sum >= 0.5) result /= sum;

	printf("%lf\n", result);
	return 0;
}
