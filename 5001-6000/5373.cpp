#include <cstdio>
#include <unordered_map>

class Color{
	public:
		enum Enum{
			None = 0,
			White = 1,
			Yellow = 2,
			Red = 3,
			Orange = 4,
			Green = 5,
			Blue = 6,
		};

		Color(): e(Enum::None){};
		constexpr Color(int x): e(static_cast<Enum>(x)){};
		constexpr Color(Enum e): e(e){};
		constexpr operator Enum() const { return e; }

		explicit operator bool() const = delete;

		char to_char(){
			switch(e){
				case Enum::White: return 'w';
				case Enum::Yellow: return 'y';
				case Enum::Red: return 'r';
				case Enum::Orange: return 'o';
				case Enum::Green: return 'g';
				case Enum::Blue: return 'b';
				default: return 0;
			}
		}
	private:
		Enum e;
};

enum class Direction{
	Up = 0,
	Down = 1,
	Front = 2,
	Back = 3,
	Left = 4,
	Right = 5
};

class Block{
	public:
		Block() = default;
		Block(std::unordered_map<Direction, Color> colors){
			for(auto [direction, color]: colors){
				_color[direction] = color;
			}

		}
		
		void set_color(Direction direction, Color color){
			_color[direction] = color;
		}


		char get_character(Direction direction){
			return _color[direction].to_char();
		}

		void horizontal(bool clockwise = false){
			Direction rotate[] = {
				Direction::Left,
				Direction::Front,
				Direction::Right, 
				Direction::Back
			};
			rotating(rotate, clockwise);
		}

		void vertical(bool clockwise = false){
			Direction rotate[] = {
				Direction::Up,
				Direction::Front,
				Direction::Down, 
				Direction::Back
			};
			rotating(rotate, clockwise);
		}

		void frontback(bool clockwise = false){
			Direction rotate[] = {
				Direction::Right,
				Direction::Up,
				Direction::Left, 
				Direction::Down
			};
			rotating(rotate, clockwise);
		}
	private:
		void rotating(Direction rotate[4], bool clockwise){
			if(clockwise){
				Color cur = _color[rotate[3]];
				for(int i = 3; i >= 1; i --){
					Color tmp = _color[rotate[i-1]];
					_color[rotate[i-1]] = cur;
					cur = tmp;
				}
				_color[rotate[3]] = cur;
				return;
			}

			Color cur = _color[rotate[0]];
			for(int i = 0; i < 3; i ++){
				Color tmp = _color[rotate[i+1]];
				_color[rotate[i+1]] = cur;
				cur = tmp;
			}
			_color[rotate[0]] = cur;

		}
		std::unordered_map<Direction, Color> _color;
};

class Cube{
	public:
		Block blocks[3][3][3];

	public:
		void ud(bool u = false, bool clockwise = false){
			int fix = 2;
			if(u){
				fix = 0;
				clockwise ^= true;
			}
			for(int i = 0; i < 9; i ++)
				blocks[fix][i/3][i%3].horizontal(!clockwise);
			Block tmp[3][3];

			if(clockwise){
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[j][3-1-i] = blocks[fix][i][j];
					}
				}
			}
			else{
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[3-1-j][i] = blocks[fix][i][j];
					}
				}
			}

			for(int i = 0; i < 9; i ++)
				blocks[fix][i/3][i%3] = tmp[i/3][i%3];

		};
		void fb(bool f = false, bool clockwise = false){
			int fix = 2;
			if(f){
				fix = 0;
				clockwise ^= true;
			}
			for(int i = 0; i < 9; i ++)
				blocks[i/3][fix][i%3].frontback(!clockwise);

			Block tmp[3][3];

			if(!clockwise){
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[j][3-1-i] = blocks[i][fix][j];
					}
				}
			}
			else{
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[3-1-j][i] = blocks[i][fix][j];
					}
				}
			}

			for(int i = 0; i < 9; i ++)
				blocks[i/3][fix][i%3] = tmp[i/3][i%3];
		};
		
		void lr(bool l = false, bool clockwise = false){
			int fix = 2;
			if(l){
				fix = 0;
				clockwise ^= true;
			}
			for(int i = 0; i < 9; i ++)
				blocks[i/3][i%3][fix].vertical(clockwise);
			
			Block tmp[3][3];

			if(clockwise){
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[j][3-1-i] = blocks[i][j][fix];
					}
				}
			}
			else{
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						tmp[3-1-j][i] = blocks[i][j][fix];
					}
				}
			}

			for(int i = 0; i < 9; i ++)
				blocks[i/3][i%3][fix] = tmp[i/3][i%3];
		};
		void print(){
			for(int i = 0; i < 3; i ++){
				for(int j = 0; j < 3; j ++){
					printf(
						"%c", blocks[0][2-i][j].get_character(Direction::Up)
					);
				}
				printf("\n");
			}
			return;
			printf("---\n");
			for(int i = 0; i < 3; i ++){
				for(int j = 0; j < 3; j ++){
					printf(
						"%c", blocks[i][2][j].get_character(Direction::Back)
					);
				}
				printf("\n");
			}
			printf("---\n");
			for(int i = 0; i < 3; i ++){
				for(int j = 0; j < 3; j ++){
					printf(
						"%c", blocks[i][j][2].get_character(Direction::Right)
					);
				}
				printf("\n");
			}
		};
};

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		Cube cube;
		for(int i = 0; i < 9; i ++)
			cube.blocks[0][i/3][i%3].set_color(Direction::Up, Color::White);

		for(int i = 0; i < 9; i ++)
			cube.blocks[2][i/3][i%3].set_color(Direction::Down, Color::Yellow);

		for(int i = 0; i < 9; i ++)
			cube.blocks[i/3][0][i%3].set_color(Direction::Front, Color::Red);

		for(int i = 0; i < 9; i ++)
			cube.blocks[i/3][2][i%3].set_color(Direction::Back, Color::Orange);

		for(int i = 0; i < 9; i ++)
			cube.blocks[i/3][i%3][0].set_color(Direction::Left, Color::Green);

		for(int i = 0; i < 9; i ++)
			cube.blocks[i/3][i%3][2].set_color(Direction::Right, Color::Blue);
		
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			char oper, r;
			scanf("\n%c%c", &oper, &r);
			
			switch(oper){
				case 'U':
				case 'D':
					cube.ud(oper=='U', r=='+');
					break;
				case 'F':
				case 'B':
					cube.fb(oper=='F', r=='+');
					break;
				case 'L':
				case 'R':
					cube.lr(oper=='L', r=='+');
					break;
			}


		}

		cube.print();
	}
		


	return 0;
};
