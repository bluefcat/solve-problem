#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>

constexpr int N = 201;
constexpr int M = 302;
char display[M][M] = { 0, };

struct Node{
	virtual void evaluate(int x, int y, int w, int h){
		for(int i = x; i < x+w; i ++){
			if(display[y][i] != '*')
				display[y][i] = '-';
			if(display[y+h][i] != '*')
				display[y+h][i] = '-';
		}
		for(int i = y; i < y+h; i ++){
			if(display[i][x] != '*')
				display[i][x] = '|';
			if(display[i][x+w] != '*')
				display[i][x+w] = '|';
		}
		display[y][x] = '*';
		display[y][x+w] = '*';
		display[y+h][x] = '*';
		display[y+h][x+w] = '*';
	};
	virtual int get_width() = 0;
	virtual int get_height() = 0;
	virtual ~Node() = default;
};

struct Window: public Node{
	char name;
	Window(char name): name(name){};
	virtual void evaluate(int x, int y, int w, int h) override {
		Node::evaluate(x, y, w, h);
		display[y][x] = name;
	};
	virtual int get_width() override { return 2; };
	virtual int get_height() override { return 2; };
	virtual ~Window() = default;
};

struct HorizontalSplit: public Node{
	Node *up, *down;
	HorizontalSplit(Node* up, Node* down)
	:up(up), down(down){};
	virtual void evaluate(int x, int y, int w, int h) override {
		Node::evaluate(x, y, w, h);
		int uh = up->get_height();
		int dh = down->get_height();

		int t = uh + dh;
		uh = (h * uh) / t;
		dh = (h * dh) / t;
		uh += h-(uh+dh);
		
		up->evaluate(x, y, w, uh);
		down->evaluate(x, y+uh, w, dh);
	};
	virtual int get_width() override {
		return std::max(up->get_width(), down->get_width());
	}
	virtual int get_height() override{
		return up->get_height() + down->get_height();
	}
	virtual ~HorizontalSplit() = default;
};

struct VerticalSplit: public Node{
	Node *left, *right;
	VerticalSplit(Node* left, Node* right)
	:left(left), right(right){};
	virtual void evaluate(int x, int y, int w, int h) override {
		Node::evaluate(x, y, w, h);

		int lw = left->get_width();
		int rw = right->get_width();
		int t = lw+rw;
		lw = (w * lw) / t;
		rw = (w * rw) / t;
		lw += w-(lw+rw);

		
		left->evaluate(x, y, lw, h);
		right->evaluate(x+lw, y, rw, h);
	};
	virtual int get_width() override {
		return left->get_width() + right->get_width();
	}
	virtual int get_height() override{
		return std::max(left->get_height(), right->get_height());
	}
	virtual ~VerticalSplit() = default;
};

int main(){
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t ++){
		int count = 0;
		Node* memory[N] = { 0, };

		char tmp[N] = { 0, };
		scanf("%s", tmp);
		std::string input{tmp};

		std::stack<Node*> s{};
		std::reverse(input.begin(), input.end());

		Node *left, *right;

		for(auto oper: input){
			switch(oper){
				case '|':
					left = s.top(); s.pop();
					right = s.top(); s.pop();
					memory[count] = new VerticalSplit{left, right};
					s.push(memory[count]);
					count ++;
					break;
				case '-':
					left = s.top(); s.pop();
					right = s.top(); s.pop();
					memory[count] = new HorizontalSplit{left, right};
					s.push(memory[count]);
					count ++;
					break;
				default:
					memory[count] = new Window{oper};
					s.push(memory[count]);
					count ++;
					break;
			}
		}
		
		Node* root = s.top(); s.pop();
		for(int i = 0; i < M; i ++)
			for(int j = 0; j < M; j ++)
				display[i][j] = 0;
			
		
		int w = root->get_width();
		int h = root->get_height();
		root->evaluate(0, 0, w, h);
		printf("%d\n", t+1);

		for(int i = 0; i < 1 *(h+1); i ++){
			for(int j = 0; j < w+1; j ++){
				if(display[i][j] == 0) printf(" ");
				else 
					printf("%c", display[i][j]);
			}
			printf("\n");
		}
		for(int i = 0; i < count; i ++){
			delete memory[i];
		}
	}
};
