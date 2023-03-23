#include <stdio.h>
#include <stdlib.h>

#define MAXN 5000

#define MAX_LENGTH 5000
#define IDTYPE long long
#define TYPE long long

typedef struct NODE{
	TYPE element;
	struct NODE* prev_node;
	struct NODE* next_node;
} node;
IDTYPE node_length = 0;

IDTYPE append_node(node** node_map, TYPE element){
	if(MAX_LENGTH <= node_length) return;

	node* target = node_map[node_length];
	if(target == NULL) target = (node*)malloc(sizeof(node));

	target->element = element;
	target->prev_node = NULL;
	target->next_node = NULL;
	
	if(node_length == 0) goto APPEND_END;

	node* prev_node = node_map[node_length-1];
	target->prev_node = prev_node;
	prev_node->next_node = target;

	APPEND_END:
	node_length ++;
	return node_length;
}

IDTYPE delete_node(node** node_map, IDTYPE id){
	if(id < 0 || node_length <= id) return node_length;

	node* prev_node = NULL;
	node* next_node = NULL;

	
}


void delete_node(node* node_map, long long id){
	if(id < 0 || MAXN <= id) return;
	

	node* prev_node = NULL;
	node* next_node = NULL;

	if(0 <= id-1)
		prev_node = node_map[id].prev_node;

	if(id+1 < MAXN)
		next_node = node_map[id].next_node;
	
	
	if(prev_node != NULL)
		prev_node->next_node = next_node;

	if(next_node != NULL)
		next_node->prev_node = prev_node;
}

void print(node* root){
	for(node* n = root; n != NULL; n = n->next_node){
		printf("[%lld] > ", n->element);
	}
	printf("\n");
	return;
}

void euler_method(node* result){

	for(node* t = result+2; t != NULL; t = t->next_node){
		long long k = t->element;
		
		node tmp_map[MAXN] = { 0, };
		int idx = 0;
		for(node* i = t; i != NULL; i = i->next_node){
			create_node(tmp_map, idx++, (i->element)*k);
		}

		for(node* n = tmp_map; n != NULL; n = n->next_node){
			delete_node(result, n->element);
		}
	}

	return;
}

int main(){
	node prime_map[MAXN] = { 0, };

	for(int i = 0; i < MAXN; i ++){
		create_node(prime_map, i, i);
	}
	
	euler_method(prime_map);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		
		if(x == 1){
			printf("1\n");
			continue;
		}

		for(node* n = prime_map+2; n != NULL; n = n->next_node){
			int y = n->element;
			if(x < y) break;
			while(x % y == 0){
				printf("%d ", y);
				x /= y;
			}

		}
		if(x != 1) printf("%d ", x);
		printf("\n");
	}
	return 0;
}
