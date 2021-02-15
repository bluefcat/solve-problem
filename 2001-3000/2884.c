#include <stdio.h>

int main(){
	int h, m;
	scanf("%d %d", &h, &m);

	int alarm = 45;

	m -= alarm;
	if(m < 0){
		m += 60;
		h --;
	}
	if (h < 0){
		h = 23;
	}

	printf("%d %d\n", h, m);
	return 0;
}
