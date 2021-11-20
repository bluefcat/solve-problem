#include <stdio.h>

typedef struct tree_{
	char name;
	struct tree_* lp;
	struct tree_* rp;
} tree;

void prefix(tree* t){
	if(t==NULL) return;
	printf("%c", t->name);
	prefix(t->lp);
	prefix(t->rp);
}

void infix(tree* t){
	if(t==NULL) return;
	infix(t->lp);
	printf("%c", t->name);
	infix(t->rp);
}

void postfix(tree* t){
	if(t==NULL) return;
	postfix(t->lp);
	postfix(t->rp);
	printf("%c", t->name);
}


int main(){
	//init
	tree node[26];
	for(int i = 0; i < 26; i ++) node[i] = (tree){ 'A'+i, NULL, NULL };
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		char p, l, r;
		scanf(" %c %c %c", &p, &l, &r);
		
		node[p-'A'].lp = (l != '.'? node+(l-'A'): NULL);
		node[p-'A'].rp = (r != '.'? node+(r-'A'): NULL);
	}
	
	prefix(node);
	printf("\n");
	infix(node);
	printf("\n");
	postfix(node);
	printf("\n");

	return 0;
}
