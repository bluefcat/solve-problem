#include <cstdio>
#include <vector>
#include <climits>
#include <tuple>
#include <cassert>

struct Node{
	int row;
	int size;
	Node* col{nullptr};
	Node *up{this}, *down{this}, *left{this}, *right{this};	
};

void dlx_cover(Node* head){
	//delete head Node
	/*
	 * [l | A | r] <-> [l | head | r] <-> [l | B | r]
	 * [l | A | r] <--------------------> [l | B | r]
	 */
	head->right->left = head->left;
	head->left->right = head->right;
	
	//circular linked list
	for(Node* it = head->down; it != head; it = it->down){
		for(Node* jt = it->right; jt != it; jt = jt->right){
			jt->down->up = jt->up;
			jt->up->down = jt->down;
			jt->col->size --;
		}
	}
}

void dlx_uncover(Node* head){
	for(Node* it = head->up; it != head; it = it->up){
		for(Node* jt = it->left; jt != it; jt = jt->left){
			jt->down->up = jt;
			jt->up->down = jt;
			jt->col->size ++;
		}
	}
	
	head->left->right = head;
	head->right->left = head;
}

bool dlx_search(Node* head, int k, std::vector<int>& solution){
	if(head->right == head) return true;

	Node* ptr = nullptr;
	int low = INT_MAX;
	
	for(Node* it = head->right; it != head; it = it->right){
		if(it->size < low){
			if(it->size == 0) return false;
			low = it->size;
			ptr = it;
		}
	}

	dlx_cover(ptr);
	
	for(Node* it = ptr->down; it != ptr; it = it->down){
		solution.push_back(it->row);
		for(Node* jt = it->right; jt != it; jt = jt->right){
			dlx_cover(jt->col);
		}

		if(dlx_search(head, k+1, solution)) return true;

		solution.pop_back();
		for(Node* jt = it->left; jt != it; jt = jt->left){
			dlx_uncover(jt->col);
		}
	}
	dlx_uncover(ptr);
	return false;
}


Node* board_[6000+1];

constexpr int get_idx(int x, int r, int c){
	return (x*17*17)+(r*17)+c;
}
constexpr int get_cell(int r, int c){
	return ((r-1)/4) * 4 + ((c-1)/4) + 1;
}

constexpr std::tuple<int, int, int> get_value(int idx){
	return {(idx / (17*17)) % 17, (idx / 17) % 17, idx % 17};
}

void init(Node* head){
	Node* cur = head;
	for(int t = 0; t < 4; t ++){
		for(int i = 1; i <= 16; i ++){
			for(int j = 1; j <= 16; j ++){
				Node* h = new Node{0, 0};
				h->up = h; h->down = h;
				h->left = cur; h->right = cur->right;
				cur->right = h;
				board_[get_idx(t, i, j)] = h;
				cur = h;
			}
		}
	}
}

template<typename T>
Node* append(T row, T head){
	Node* result = new Node{row};
	Node* h = board_[head];

	h->size ++;
	Node* it = h;
	for(;it->down != h; it = it->down);
	
	result->up = it; 
	it->down = result;
	result->down = h; 
	h->up = result;
	result->col = h;

	return result;
}

template<typename T, typename... Args>
Node* append(T row, T head, Args... args){
	Node* result = append(row, head);
	Node* next = append(args...);
	
	result->right = next; 
	result->left = next->left;

	next->left->right = result;
	next->left = result;
	return result;
}



int main(){
	std::vector<int> solution{};
	Node* head = new Node{0, 0};
	
	init(head);

	int board[16][16] = { 0, };
	for(int i = 1; i <= 16; i ++){
		scanf("\n");
		for(int j = 1; j <= 16; j ++){
			char c;
			int l = 0, r = 0;
			scanf("%c", &c);
			if(c == '-'){
				l = 1; r = 17;
			}
			else{
				l = c-'A'+1;
				r = l+1;
			}
			
			for(int tmp = l; tmp < r; tmp ++){
				int row = get_idx(i, j, tmp);
				int h0 = get_idx(0, i, j);
				int h1 = get_idx(1, i, tmp);
				int h2 = get_idx(2, j, tmp);
				int h3 = get_idx(3, get_cell(i, j), tmp);
				append(
					row, h0, row, h1, row, h2, row, h3
				);

				board[i-1][j-1] = tmp;
			}
		}
	}
		
	bool result = dlx_search(head, 0, solution);

	for(auto& x: solution){
		auto [a, b, c] = get_value(x);
		board[a-1][b-1] = c;
	}

	for(int i = 0; i < 16; i ++){
		for(int j = 0; j < 16; j ++) printf("%c", board[i][j]+'A'-1);
		printf("\n");
	}


	return 0;
}
