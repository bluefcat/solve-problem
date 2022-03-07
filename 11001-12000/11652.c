#include <stdio.h>

#define KMAX 131071
typedef struct hash_{
	long long key;
	int count;

	struct hash_* next;
} hash;

hash bucket[KMAX];
hash plus[KMAX]; int cnt;

//key, count
long long result[2];

void insert(long long key){
	int n = key % KMAX;
	
	hash* target = bucket + n;
	
	//empty this place
	if(target->count == 0){
		target->key = key;
		target->count ++;
		goto REFLESH;
	}

	if(target->key == key){
		target->count ++;
		goto REFLESH;
	}
	while(target->next && target->key != key){
		target = target->next;
	}

	if(target->key == key){
		target->count ++;
		goto REFLESH;
	}

	if(target->next == NULL){
		target->next = plus + cnt; cnt ++;
		
		plus[cnt-1].key = key;
		plus[cnt-1].count ++;

		target = plus + cnt - 1;
	}
	
REFLESH:
	if(result[1] < target->count){
		result[0] = key;
		result[1] = target->count;
	}
	else if(result[1] == target->count && result[0] > key){
		result[0] = key;
	}

	return;
}



int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		long long tmp;
		scanf("%lld", &tmp);
		insert(tmp);
	}

	printf("%lld\n", result[0]);

	return 0;
}
