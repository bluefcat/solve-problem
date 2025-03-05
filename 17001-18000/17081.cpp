#include <cstdio>
#include <unordered_map>
#include <string>
#include <memory>

#include <cstring>
#include <tuple>

using std::unordered_map;
using std::shared_ptr;

constexpr int N = 101;
constexpr int OPER = 5001;

enum class EquipmentType{
	Weapon = 0,
	Armor = 1,
	Opart = 2,
};

enum class MonsterType{
	Normal = 0,
	Boss = 1,
};

enum class Phase{
	BattleInit = 0,
	FirstAttack = 1,
	PlayerAttack = 2,
	EnemyAttack = 3,
	BattleDeInit = 4,
	BattleVictory = 5,
	GainExp = 6,
	BattleDefeat = 8,
	ActiveTrap = 9,

	BossInit = 20,
	BossFirstAttack = 21,
};

class Info;
class Info{

};

class EquipmentInfo: public Info{
	protected:
		EquipmentType _type;
	public:
		EquipmentInfo(EquipmentType type)
		: _type(type){}

		EquipmentType get_type(){ return _type; }
		virtual void activate(const Phase&, Info&){};
		virtual std::string get_describe(){ return ""; };
};


class ValueInfo: public Info{
	public:
		int value = 0;
		bool dx_flag = false;
		bool hu_flag = false;
};

class PlayerInfo: public Info{
	public:
		int px, py;
		int x, y;
	private:
		int _lv;
		int _max_hp, _cur_hp;
		int _atk, _def;
		int _max_exp, _cur_exp;

		shared_ptr<EquipmentInfo> _weapon;
		shared_ptr<EquipmentInfo>  _armor;

		unordered_map<std::string, shared_ptr<EquipmentInfo>> _oparts;

		int _damage = 0;
		
	public:
		PlayerInfo(int lv, int max_hp, int atk, int def)
		:_lv(lv), _max_hp(max_hp), _cur_hp(max_hp), 
		 _atk(atk), _def(def), _max_exp(exp_table()){
		}

		void init(const Phase& phase){
			for(auto [key, opart]: _oparts)
				if(opart) opart->activate(phase, *this);
		}

		ValueInfo attack(const Phase& phase, int turn){
			ValueInfo result{Info{}, _atk, _oparts["DX"] != nullptr};
			if(_weapon)
				_weapon->activate(phase, result);

			for(auto [key, opart]: _oparts)
				if(opart) opart->activate(phase, result);
			return result;
		}

		void heal(int h){
			_cur_hp = std::min(_cur_hp+h, _max_hp);
		}

		void damage(const Phase& phase, ValueInfo damage){
			
			if(phase == Phase::ActiveTrap){
				ValueInfo damage{Info(), 5};
				for(auto [key, opart]: _oparts)
					if(opart) opart->activate(phase, damage);

				_cur_hp = std::max(0, _cur_hp-damage.value);	
				return;
			}

			ValueInfo def{Info(), _def};

			if(_armor)
				_armor->activate(phase, def);

			for(auto [key, opart]: _oparts)
				if(opart) opart->activate(phase, def);
			
			if(def.hu_flag) return;
			int value = std::max(1, damage.value - def.value);
			_cur_hp = std::max(0, _cur_hp-value);	
		}

		void get_exp(int exp){
			ValueInfo result{Info(), exp};
			for(auto [key, opart]: _oparts)
				if(opart){ 
					opart->activate(Phase::GainExp, result);
					opart->activate(Phase::BattleVictory, *this);
				}

			_cur_exp += result.value;
			if(_cur_exp >= _max_exp){
				_lv ++;
				_max_hp += 5;
				_cur_hp = _max_hp;
				_atk += 2;
				_def += 2;
				_max_exp = exp_table();
				_cur_exp = 0;
			}
		}

		bool has_equipment(EquipmentType type){
			return true;
		}

		void unequip(std::string key){
			if(_oparts[key]) _oparts[key] = nullptr;
		}

		void defeat(){
			for(auto [key, opart]: _oparts)
				if(opart){ 
					opart->activate(Phase::BattleDefeat, *this);
				}
		}

		void get_equipment(shared_ptr<EquipmentInfo> equip){
			switch(equip->get_type()){
				case EquipmentType::Weapon:
					_weapon = equip;
					break;
				case EquipmentType::Armor:
					_armor = equip;
					break;
				case EquipmentType::Opart:
					if(_oparts.size() >= 4) return;
					_oparts[equip->get_describe()] = equip;
					break;
			}
		}

		char get_character(){
			return '@';
		}

		bool is_live(){
			return _cur_hp > 0;
		}

		void print(){
			std::string patk{"0"}, pdef{"0"};
			if(_weapon)
				patk = _weapon->get_describe();
			if(_armor)
				pdef = _armor->get_describe();

			printf(
				"LV : %d\nHP : %d/%d\nATT : %d+%s\nDEF : %d+%s\nEXP : %d/%d\n", 
				_lv, _cur_hp, _max_hp, 
				_atk, patk.c_str(), 
				_def, pdef.c_str(), 
				_cur_exp, _max_exp
			);
		}
		
	private:
		constexpr int exp_table() const {
			return 5*_lv;	
		}
};

class Weapon: public EquipmentInfo{
	private:
		int _value;
	public:
		Weapon(EquipmentType type, int value)
		:EquipmentInfo(type), _value(value){}

		void activate(const Phase& phase, Info& info) override {
			static_cast<ValueInfo&>(info).value += _value;
			return;
		}

		std::string get_describe() override {
			return std::to_string(_value);
		}
		
};

class Armor: public EquipmentInfo{
	private:
		int _value;
	public:
		Armor(EquipmentType type, int value)
		:EquipmentInfo(type), _value(value){}

		void activate(const Phase& phase, Info& info) override {
			static_cast<ValueInfo&>(info).value += _value;
			return;
		}

		std::string get_describe() override {
			return std::to_string(_value);
		}
		
};

class Opart: public EquipmentInfo{
	private:
		std::string _effect;
	public:
		Opart(EquipmentType type, std::string effect)
		:EquipmentInfo(type), _effect(effect){}

		void activate(const Phase& phase, Info& info) override {
			if(_effect == "HR" && phase == Phase::BattleVictory){
				PlayerInfo& player = static_cast<PlayerInfo&>(info);
				player.heal(3);
				return;
			}

			if(_effect == "RE" && phase == Phase::BattleDefeat){
				PlayerInfo& player = static_cast<PlayerInfo&>(info);
				player.x = player.px;
				player.y = player.py;
				player.heal(9999999);
				player.unequip("RE");
				return;
			}

			if(_effect == "CO" && phase == Phase::FirstAttack){
				ValueInfo& value = static_cast<ValueInfo&>(info);
				if(value.dx_flag){
					value.value *= 3;
					return;
				}
				value.value *= 2;
				return;
			}

			if(_effect == "EX" && phase == Phase::GainExp){
				ValueInfo& value = static_cast<ValueInfo&>(info);
				value.value = value.value + ((value.value*2)/10);
				return;
			}

			if(_effect == "DX" && phase == Phase::ActiveTrap){
				ValueInfo& value = static_cast<ValueInfo&>(info);
				value.value = 1;
				return;
			}

			if(_effect == "HU" && phase == Phase::BossInit){
				PlayerInfo& player = static_cast<PlayerInfo&>(info);
				player.heal(9999999);
				return;
			}
			if(_effect == "HU" && phase == Phase::BossFirstAttack){
				ValueInfo& value = static_cast<ValueInfo&>(info);
				value.hu_flag = true;
				return;
			}

			return;
		}

		std::string get_describe() override {
			return _effect;
		}
		
};

class EnemyInfo: public Info{
	public:
		std::string _name;
		int _atk, _def;
		int _max_hp, _cur_hp;
		int _exp;

		MonsterType type;

	public:
		void set_property(
			const std::string name, 
			int atk, int def, int max_hp, int cur_hp, int exp
		){
			_name = name;
			_atk = atk, _def = def, _max_hp = max_hp, _cur_hp = cur_hp;
			_exp = exp;
		}

		ValueInfo attack(const Phase& phase, int turn){
			ValueInfo result{Info(), _atk};
			return result;
		}

		void damage(const Phase& phase, ValueInfo damage){
			int value = std::max(1, damage.value - _def);
			_cur_hp -= value;
		}

		int exp(){
			return _exp;
		}

		char get_character(){
			if(type == MonsterType::Normal) return '&';
			return 'M';
		};

		bool is_live(){
			return _cur_hp > 0;
		}

		std::string get_name(){
			return _name;
		}

		void victory(){
			_cur_hp = _max_hp;
		}
};

class Battle{
	public:
		bool battle(
			shared_ptr<PlayerInfo> player, 
			shared_ptr<EnemyInfo> enemy
		){
			int turn = 1;
			if(enemy->type == MonsterType::Boss)
				player->init(Phase::BossInit);

			while(true){
				enemy->damage(
					Phase::PlayerAttack,
					player->attack(
						(turn==1)?Phase::FirstAttack:Phase::PlayerAttack, turn
					)
				);
				
				if(!enemy->is_live()){ 
					player->get_exp(enemy->exp());
					return true;
				}

				player->damage(
					(turn==1 && enemy->type == MonsterType::Boss)?
					Phase::BossFirstAttack:Phase::EnemyAttack,
					enemy->attack(Phase::EnemyAttack, turn)
				);
				
				if(!player->is_live()){
					player->defeat();
					enemy->victory();
					return false;
				}

				turn ++;
			}
			return false;
		}
};

static Battle battle{};

class Object{
	public:
		virtual bool walkable(){ return true; };
		virtual bool evaluate(shared_ptr<PlayerInfo>) = 0;
		virtual char get_character() = 0;
		virtual ~Object(){};
};

class Empty: public Object{
	public:
		bool evaluate(shared_ptr<PlayerInfo>){ return true; }
		char get_character(){ return '.'; }
};

class Wall: public Object{
	public:
		bool walkable(){ return false; }
		bool evaluate(shared_ptr<PlayerInfo>){ return true; }
		char get_character(){ return '#'; }
};

class Trap: public Object{
	public:
		bool evaluate(shared_ptr<PlayerInfo> p){
			ValueInfo value{Info(), 5};
			p->damage(Phase::ActiveTrap, value);
			if(!p->is_live()) p->defeat();
			return true;
		}

		char get_character(){ return '^'; }
};

class Box: public Object{
	private:
		shared_ptr<EquipmentInfo> _equipment;
	public:
		Box(shared_ptr<EquipmentInfo> equipment)
		:_equipment(equipment){}

		bool evaluate(shared_ptr<PlayerInfo> player){ 
			player->get_equipment(_equipment);
			return false; 
		}
		char get_character(){ return 'B'; }
};

class Enemy: public Object{
	private:
		shared_ptr<EnemyInfo> _enemy;
	public:
		Enemy(shared_ptr<EnemyInfo> enemy)
		:_enemy(enemy){}

		bool evaluate(shared_ptr<PlayerInfo> player){ 
			return !battle.battle(player, _enemy); 
		}
		char get_character(){
			return _enemy->get_character();
		}

		std::string get_name(){
			return _enemy->get_name();
		}
};

class Field{
	private:
		shared_ptr<Object> _wall = std::make_shared<Wall>();
		shared_ptr<Object> _empty = std::make_shared<Empty>();
		shared_ptr<Object> _field[N][N] = { nullptr, };

	public:
		int height, width;
	
	public:
		Field(int height, int width)
			:height(height), width(width){}
		
		void set_object(int y, int x, shared_ptr<Object> object){
			if(object == nullptr){
				_field[y][x] = _empty;
				return;
			}
			_field[y][x] = object;
		}

		auto get_object(int y, int x){
			if(!(0 <= y && y < height) ||
			   !(0 <= x && x < width)
			){
				return _wall;
			}

			if(!_field[y][x]) return _empty;
			return _field[y][x];
		}
};


class Game{
	private:
		shared_ptr<Field> _field;

		int _turn = 0;

		shared_ptr<PlayerInfo> _player{nullptr};
		unordered_map<int, shared_ptr<EnemyInfo>> _enemys{};
		unordered_map<int, shared_ptr<EquipmentInfo>> _equipments{};
	
		unordered_map<char, std::tuple<int, int>> _actions{
			{'U', {-1, 0}}, 
			{'R', {0, 1}}, 
			{'D', {1, 0}}, 
			{'L', {0, -1}}
		};

		bool _gameover = false;
		bool _gameclear = false;

		std::string _target{""};

	public:
		Game(int height, int width, shared_ptr<PlayerInfo> player)
		:_player(player){
			_field = std::make_shared<Field>(height, width);
		}

		void set_object(int y, int x, char type){
			int id = get_id(y, x);
			switch(type){
				case '@':
					_player->y = y; _player->x = x;
					_player->py = y; _player->px = x;
					break;
				case '#':
					_field->set_object(y, x, std::make_shared<Wall>());
					break;
				case 'B':
					_equipments[id] = std::make_shared<EquipmentInfo>(EquipmentType::Weapon);
					break;
				case '^':
					_field->set_object(y, x, std::make_shared<Trap>());
					break;
				case '&':
					_enemys[id] = std::make_shared<EnemyInfo>();
					_enemys[id]->type = MonsterType::Normal;
					break;
				case 'M':
					//Boss
					_enemys[id] = std::make_shared<EnemyInfo>();
					_enemys[id]->type = MonsterType::Boss;
					break;
				default:
					// case '.'
					break;
			}
		}

		void set_enemy(
				int y, int x, 
				const std::string name,
				int atk, int def, int max_hp, int exp
		){
			int id = get_id(y, x);
			_enemys[id]->set_property(
				name, atk, def, max_hp, max_hp, exp
			);
			_field->set_object(
				y, x, std::make_shared<Enemy>(_enemys[id])
			);
		}

		void set_equipment(
			int y, int x, shared_ptr<EquipmentInfo> equipment
		){
			int id = get_id(y, x);
			_equipments[id] = equipment;
			_field->set_object(
				y, x, std::make_shared<Box>(_equipments[id])
			);
			return;
		}	

		void input(char command){
			if(_gameover) return;
			_turn ++;

			auto [dy, dx] = _actions[command];
			int y = _player->y, x = _player->x;
			int ny = _player->y + dy, nx = _player->x + dx;

			if(!_field->get_object(ny, nx)->walkable()){
				_field->get_object(y, x)->evaluate(_player);
				goto JUDGE;
			}
			_player->y = ny; _player->x = nx;
			y = ny;
			x = nx;
			if(!_field->get_object(ny, nx)->evaluate(_player))
				_field->set_object(ny, nx, nullptr);

			JUDGE:
			if(!_player->is_live()){
				if(_enemys[get_id(y, x)]){
					_target = _enemys[get_id(y, x)]->get_name();
				}
				else{
					_target = "SPIKE TRAP";
				}
				_gameover = true;
			}
			if(
				_enemys[get_id(y, x)] && 
				_enemys[get_id(y, x)]->type == MonsterType::Boss &&
				!_enemys[get_id(y, x)]->is_live()
			) _gameclear = true;
			return;
		}

		void print(){
			for(int i = 0; i < _field->height; i ++){
				for(int j = 0; j < _field->width; j ++){
					if(_player->y == i && _player->x == j && !_gameover){
						printf("@");
					}
					else{
						printf("%c", _field->get_object(i, j)->get_character());
					}
				}
				printf("\n");
			}
			printf("Passed Turns : %d\n", _turn);
			_player->print();
			if(_gameclear){
				printf("YOU WIN!\n");
			}
			else if(_gameover){
				printf("YOU HAVE BEEN KILLED BY %s..\n", _target.c_str());

			}
			else{
				printf("Press any key to continue.\n");
			}
		}

		int get_enemy_count() const {
			return _enemys.size();
		}

		int get_equipment_count() const {
			return _equipments.size();
		}

		int get_id(int y, int x) const { 
			return y * _field->width + x; 
		}

		bool is_finish(){
			return _gameover || _gameclear;
		}

		~Game(){
		}

};


int main(){
	shared_ptr<PlayerInfo> player = 
		std::make_shared<PlayerInfo>(1, 20, 2, 2);

	int n, m;
	char oper[OPER];
	scanf("%d %d", &n, &m);
	Game game{n, m, player};

	for(int i = 0; i < n; i ++){
		scanf("\n");
		for(int j = 0; j < m; j ++){
			char c; 
			scanf("%1c", &c);
			game.set_object(i, j, c);
		}
	}

	scanf("%s", oper);

	for(int i = 0; i < game.get_enemy_count(); i ++){
		int r, c;
		char s[11];
		int w, a, h, e;
		scanf("%d %d %s %d %d %d %d", &r, &c, s, &w, &a, &h, &e);
		game.set_enemy(
			r-1, c-1, std::string{s}, w, a, h, e
		);
	}

	for(int i = 0; i < game.get_equipment_count(); i ++){
		int r = 0, c = 0; 
		char t;
		int n = 0; char s[3];
		scanf("%d %d %c", &r, &c, &t);
		switch(t){
			case 'W':
				scanf("%d", &n);
				game.set_equipment(r-1, c-1, std::make_shared<Weapon>(
					EquipmentType::Weapon, n
				));
				break;
			case 'A':
				scanf("%d", &n);
				game.set_equipment(r-1, c-1, std::make_shared<Armor>(
					EquipmentType::Armor, n
				));
				break;
			case 'O':
				scanf("%s", s);
				game.set_equipment(r-1, c-1, std::make_shared<Opart>(
					EquipmentType::Opart, std::string{s}
				));
				break;
		}
	}

	for(int i = 0; i < strlen(oper); i ++){
		//printf("%s\n", oper);
		//for(int j = 0; j < i; j ++) printf(" ");
		//printf("^\n");
		game.input(oper[i]);
		//game.print();
		//printf("---\n");
		if(game.is_finish()) break;
	}

	game.print();

	return 0;
}
