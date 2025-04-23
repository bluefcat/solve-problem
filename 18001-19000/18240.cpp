#include <cstdio>

struct Node{
	int id = -1;
	int x = -1;
	Node *left{nullptr}, *right{nullptr};
};

int arr[300002];

Node tree[300002];
int count = 0;
bool flag = false;

void set_node(Node* head, int depth){
	if(flag) return;
	if(depth == 0){
		if(head->left == nullptr)
			head->left = tree + count+1;
		else if(head->right == nullptr)
			head->right = tree + count+1;
		else return;
		count ++;
		tree[count].id = count;
		flag = true;
		return;
	}
	if(head->left) 
		set_node(head->left, depth - 1);

	if(head->right)
		set_node(head->right, depth - 1);
}

void predict_node(Node* head, int& count){
	if(head->left)
		predict_node(head->left, count);
	arr[head->id] = count;
	count ++;
	if(head->right)
		predict_node(head->right, count);
}


int main(){
	tree[0].id = 0; //head;

	int n, has_answer = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; i ++){
		int depth;
		scanf("%d", &depth);
		flag = false;
		set_node(tree+0, depth-1);
		if(flag == false) has_answer = -1;
	}
	if(has_answer == -1){
		printf("-1\n");
		return 0;
	}
	int count = 1;
	predict_node(tree+0, count);
	for(int i = 0; i < n; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
