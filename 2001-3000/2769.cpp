#include <cstdio>
#include <string>
#include <stack>
#include <memory>
#include <unordered_map>

constexpr int N = 255;

std::unordered_map<char, int> orders = {
	{'(', 1}, {')', 1}, {'~', 6}, {'&', 5}, {'^', 4}, {'|', 3}
};

std::unordered_map<char, bool> variables{};
std::unordered_map<char, bool> exists{};

class Form{
	public:
		virtual bool eval(){ return false; };
		virtual std::string str(){ return "";};

		virtual const char get_operator(){ return 'N'; };

		virtual std::shared_ptr<Form> get_child(){
			return nullptr;
		}

		virtual ~Form(){};

};

class Variable: public Form{
	private:
		std::string _id;
		bool* _x;
	public:
		Variable(std::string id, bool* x): _id(id), _x(x){}
		virtual bool eval(){ return *_x; }
		virtual const char get_operator(){ return _id.c_str()[0]; }
		virtual std::string str() { return _id; }
};

class True: public Form{
	public:
		True(){};
		virtual bool eval(){ return true; }
		virtual const char get_operator(){ return 'T'; }
		virtual std::string str(){ return "True"; }
};

class False: public Form{
	public:
		False(){};
		virtual bool eval(){ return false; }
		virtual const char get_operator(){ return 'F'; }
		virtual std::string str(){ return "False"; }
};

std::shared_ptr<True> ftrue{std::make_shared<True>()};
std::shared_ptr<False> ffalse{std::make_shared<False>()};

class Not: public Form{
	private:
		std::shared_ptr<Form> _form;
	public:
		Not(std::shared_ptr<Form> form): _form(form){}
		virtual bool eval(){ return !_form->eval(); };
		virtual const char get_operator(){ return '~'; }
		virtual std::string str() { return "(~" + _form->str() +")"; };

		virtual std::shared_ptr<Form> get_child(){
			return _form;
		};

		virtual ~Not(){
			
		};
};

class Operator: public Form{
	protected:
		std::shared_ptr<Form> _left;
		std::shared_ptr<Form> _right;
	public:
		Operator(std::shared_ptr<Form> left, std::shared_ptr<Form> right)
		: _left(left), _right(right){};

		virtual bool eval() = 0;
		virtual const char get_operator() = 0;
		virtual std::string str() = 0;

		virtual ~Operator(){
			
			
		}
};

class And: public Operator{
	public:
		And(std::shared_ptr<Form> left, std::shared_ptr<Form> right): Operator(left, right){};
		virtual bool eval(){ return _left->eval() && _right->eval();};
		virtual const char get_operator(){ return '&'; }
		virtual std::string str(){ return "(" + _left->str() + "&" + _right->str() +")"; }
};

class Or: public Operator{
	public:
		Or(std::shared_ptr<Form> left, std::shared_ptr<Form> right): Operator(left, right){};
		virtual bool eval(){ return _left->eval() || _right->eval();};
		virtual const char get_operator(){ return '|'; }
		virtual std::string str(){ return "(" + _left->str() + "|" + _right->str() +")"; }
};

class Xor: public Operator{
	public:
		Xor(std::shared_ptr<Form> left, std::shared_ptr<Form> right): Operator(left, right){};
		virtual bool eval(){ return _left->eval() ^ _right->eval();};
		virtual const char get_operator(){ return '^'; }
		virtual std::string str(){ return "(" + _left->str() + "^" + _right->str() +")"; }
};

std::shared_ptr<Form> parsing(std::string form){
		std::stack<std::shared_ptr<Form>> s{};
		
		for(char x: form){
			if(orders[x] == 0){
				s.push(std::make_shared<Variable>(std::string{x}, &variables[x]));
				exists[x] = true;
				continue;
			}

			std::shared_ptr<Form> operand[2] = { nullptr, nullptr };
			switch(x){
				case '~':
					operand[0] = s.top(); s.pop();
					if(operand[0]->get_operator() == '~'){
						//Not Not A == A
						s.push(operand[0]->get_child());
					}
					else if(operand[0]->get_operator() == 'T'){
						s.push(ffalse);
					}
					else if(operand[0]->get_operator() == 'F'){
						s.push(ftrue);
					}
					else
						s.push(std::make_shared<Not>(operand[0]));
					break;
				case '&':
					operand[0] = s.top(); s.pop();
					operand[1] = s.top(); s.pop();
					if(operand[0]->str() == operand[1]->str())
						s.push(operand[0]);
					else if(
						operand[0]->get_operator() == 'F' ||
						operand[1]->get_operator() == 'F'
					) s.push(ffalse);
					else if(
						operand[0]->get_operator() == '~' ||
						operand[1]->get_operator() == '~' 
					){
						if(operand[0]->get_operator() != '~'){
							if(operand[0]->str() == operand[1]->get_child()->str()){
								s.push(ffalse);
								break;
							}
						}
						else{
							if(operand[0]->get_child()->str() == operand[1]->str()){
								s.push(ffalse);
								break;
							}
						}
						s.push(std::make_shared<And>(operand[0], operand[1]));
					}
					else
						s.push(std::make_shared<And>(operand[0], operand[1]));
					break;
				case '^':
					operand[0] = s.top(); s.pop();
					operand[1] = s.top(); s.pop();
					if(operand[0]->str() == operand[1]->str())
						s.push(ffalse);
					else if(
						operand[0]->get_operator() == 'T' &&
						operand[1]->get_operator() == 'T'
					  )
						s.push(ffalse);
					else if(
						operand[0]->get_operator() == 'F' &&
						operand[1]->get_operator() == 'F'
					)
						s.push(ffalse);
					else if(
						operand[0]->get_operator() == 'T' &&
						operand[1]->get_operator() == 'F'
					  ) s.push(ftrue);
					else if(
						operand[0]->get_operator() == 'F' &&
						operand[1]->get_operator() == 'T'
					  ) s.push(ftrue);
					else if(
						operand[0]->get_operator() == 'T' ||
						operand[1]->get_operator() == 'T'
					  ){
						if(operand[0]->get_operator() != 'T')
							s.push(std::make_shared<Not>(operand[0]));
						else
							s.push(std::make_shared<Not>(operand[1]));
					}
					else if(
						operand[0]->get_operator() == 'F' ||
						operand[1]->get_operator() == 'F'
					  ){
						if(operand[0]->get_operator() != 'F')
							s.push(operand[0]);
						else
							s.push(operand[1]);
					}
					else
						s.push(std::make_shared<Xor>(operand[0], operand[1]));
					break;
				case '|':
					operand[0] = s.top(); s.pop();
					operand[1] = s.top(); s.pop();
					if(operand[0]->str() == operand[1]->str())
						s.push(operand[0]);
					else if(
						operand[0]->get_operator() == 'T' ||
						operand[1]->get_operator() == 'T'
					)
						s.push(ftrue);
					else
						s.push(std::make_shared<Or>(operand[0], operand[1]));
					break;
			}

		}

		return s.top();
}

std::string get_postfix(const char* target){
	std::string result{};
	std::stack<char> s{};	

	
	const char* p = target + 0;

	while(*p){
		char oper = 0;
		if(orders[*p] == 0){ //variables
			result += (*p);
			p ++;
			continue;
		}
		
		switch(*p){
			case '(': 
				s.push(*p);
				break;
			case ')':
				while(!s.empty()){
					oper = s.top(); s.pop();
					if(oper == '(') break;
					result += oper;
				}
				break;
			default:
				while(!s.empty() && orders[s.top()] > orders[*p]){
					oper = s.top(); s.pop();
					result += oper;
				}
				s.push(*p);
				break;
		}
		p++;
	}

	while(!s.empty()){
		result += s.top(); s.pop();
	}

	return result;
}

int main(){
	for(char symbol = 'a'; symbol <= 'z'; symbol ++){
		variables[symbol] = false;
		exists[symbol] = false;
	}

	const char* form[] = {
		"a&(a&b)",
		"a&(~a)",
		"a&~~b&(a&a)&(a|a)&(a^a)&(a&b)&(a&b)",
		"(~~a&b)&(a&b)",
		"~(a^a)",
		"(~~a&b)",
		"(a&~~b)",
		"(~a&b)&(a&b~)|~(a|b)&c",
		"(a&b&c)&a"
	};


	for(int i = 0; i < 9; i ++){
		std::shared_ptr<Form> result = parsing(get_postfix(form[i]));
		printf("input: %s\n", form[i]);
		printf("%s = %d\n", result->str().c_str(), result->eval());
		printf("________\n");
		
	}

	return 0;

	int T = 1;

	while(T--){
		char tmp[N] = { 0, };
		scanf("%s", tmp);

		std::string form{tmp};

	}

	return 0;
}
