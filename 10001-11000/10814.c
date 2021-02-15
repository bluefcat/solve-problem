#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _User{
	int age;
	char name[101];
} User;

int compare(const void* x, const void* y){
	User* ux = (User*)x;
	User* uy = (User*)y;

	if(ux->age > uy->age){
		return 1;
	}
	else{
		return -1;
	}
}

int main(){
	int n;
	scanf("%d", &n);

	User* users = (User*)malloc(sizeof(User)*n);
	for(int i = 0; i < n; i ++){
		scanf("%d %s", &(users[i].age), (users[i].name));
	}

	qsort(users, n, sizeof(User), compare);
	
	for(int i = 0; i < n; i ++){
		printf("%d %s\n", users[i].age, users[i].name);
	}

	free(users);

	return 0;
}
