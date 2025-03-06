#include <cstdio>
#include <string>
#include <memory>
#include <unordered_map>
#include <tuple>

using lint = long long;
using std::shared_ptr;
using std::string;
using std::unordered_map;

class Player;
class Useable{
	public:
		virtual void use(Player&) = 0;
};

class DurationUseable: public Useable{
	public:
		virtual void use(Player&) = 0;
		virtual void done(Player&) = 0;
		virtual lint get_duration() const = 0;
};


class UseSlot{
	private:
		shared_ptr<Useable> _useable;
		constexpr bool _can_use(const Player& player) const;
		
	public:
		void set(shared_ptr<Useable> useable);
		void use(Player& player);
};

class DurationSlot{
	private:
		shared_ptr<DurationUseable> _duration_useable;
		lint _duration = 0;
		constexpr bool _can_use(const Player& player) const;
	public:
		void set(shared_ptr<DurationUseable> duration_useable);
		void use(Player& player);
		void update(Player& player);
		bool is_run();
};

class Player{
	private:
		lint _init_count = 1;
	public:
		lint count = 0;
		lint base_x = 0;
		lint jump = 0;
		lint dash = 0;
		lint maxdrop = 0;

		bool quick = false, accel = false, weak = false, motion = false;
		bool rotate = false, depend = false;

		lint x = 0, y = 0;
		lint vx = 0, vy = 0;
		
		UseSlot useslot{};
		DurationSlot duration_useslots[100];

		lint _calc_vx(){
			return (1 + dash + 5 * quick) * 
				   (1 + accel) * base_x * 
				   (1 - motion);
		}

	public:

		void print(){
			printf("pos (%lld %lld) v(%lld %lld)\n", x, y, vx, vy);
			printf("(dash %lld jump %lld maxdrop %lld)\n", 
					dash, jump, maxdrop);
			printf("(quick %d accel %d weak %d motion %d rotate %d depend %d)\n",
					quick, accel, weak, motion, rotate, depend);
			printf("(1+%lld+5*%d)*(1+%d)*%lld*(1-%d) = %lld\n", dash, quick, accel, base_x, motion, _calc_vx());
			printf("(base_g/(1+%d))\n", weak);
		}

		constexpr bool is_dash() const {
			return (dash > 0);
		}

		constexpr bool is_landing() const {
			return (y == 0) && !rotate;
		}

		void set_rotate(){
			if(y == 0 && rotate){
				vy *= -1;
				rotate = false;
			} 
		}

		void set_dash(lint d){
			dash = d;
			count = _init_count;
		}

		void reduce_dash(){
			if(count != 0){
				count --;
				return;
			}
			if(!is_dash()) return;

			dash = std::max((lint)0, dash-1);
			count = _init_count;
			if(dash == 0 && this->depend) 
				this->depend = false;
		}

		void update(){
			for(auto& du: duration_useslots)
				if(du.is_run()) du.update(*this);
		}

		void input(
			shared_ptr<Useable> useable,
			shared_ptr<DurationUseable> duration_useable
		){
			if(useable){
				useslot.set(useable);
				useslot.use(*this);
			}
			if(duration_useable){
				int idx = 0;
				for(;duration_useslots[idx].is_run(); idx++);
				auto& du = duration_useslots[idx];
				du.set(duration_useable);
				du.use(*this);
			}
		}

		void move_horizontal(){
			vx = _calc_vx();
			x += vx;
		}

		void move_vertical(){
			if(depend) vy = vx;
			y = std::max((lint)0, y + vy);
		}

		void affect_gravity(lint base_g){
			if(
				this->is_dash() || this->motion
			) return;

			lint g = (base_g / (1+weak));
			vy = std::max(-maxdrop, vy - g);
		}

		void calc_bundle(){
			if(
				this->is_dash() || 
				motion != 0 ||
				quick != false ||
				accel != false ||
				weak != false ||
				depend != false ||
				vy != -maxdrop 
			)
				return;
			
			lint bundle = y / maxdrop + ((y % maxdrop) != 0);
			//printf("pos [%lld %lld]\n(m, b, v) [%lld %lld %lld]\n", x, y, maxdrop, bundle, _calc_vx());
			y = 0;
			x += bundle * _calc_vx();
		}
};

constexpr bool UseSlot::_can_use(const Player& player) const {
	return (!player.is_dash()) && !(player.motion);
}
		
void UseSlot::set(shared_ptr<Useable> useable){
	_useable = useable;
}

void UseSlot::use(Player& player){
	if(!_can_use(player)){
		return;
	}

	return _useable->use(player);
};

constexpr bool DurationSlot::_can_use(const Player& player) const {
	return (!player.is_dash()) && !(player.motion);
}
void DurationSlot::set(shared_ptr<DurationUseable> duration_useable){
	_duration_useable = duration_useable;
	_duration = duration_useable->get_duration();
}

void DurationSlot::use(Player& player){
	if(!_can_use(player)){ 
		_duration = 0;
		return;
	}
	return _duration_useable->use(player);
}

void DurationSlot::update(Player& player){
	_duration --;
	if(_duration <= 0)
		_duration_useable->done(player);
}

bool DurationSlot::is_run(){
	return _duration > 0;
}

class None: public Useable{
	public:
		void use(Player& player) override {
		}
};

//move skill
class Dash: public Useable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			if(player.quick) player.quick = false;
			player.set_dash(5);
			player.vy = 0;
		}
};

class AirJump: public Useable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.vy = player.jump;
		}
};

class QuickDrop: public Useable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.quick = true;
			player.vy = -player.maxdrop;
		}
};

//attack skill
class RotateAttack: public Useable{
	private:
		int count = 1;
	public:
		void use(Player& player) override {
			if(count == 0) return;
			player.rotate = true;
			count --;
		}
};

class HorizontalAttak: public Useable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			if(player.quick) player.quick = false;
			player.set_dash(5);
			player.vy = 0;
		}
};

class UpwardAttack: public Useable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			if(player.quick) player.quick = false;
			player.set_dash(5);
			player.depend = true;
		}
};

class Accelate: public DurationUseable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.accel = true;	
		}

		void done(Player& player) override {
			player.accel = false;
		}

		lint get_duration() const override {
			return 600;
		}
};

class GravityWeak: public DurationUseable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.weak = true;
		}

		void done(Player& player) override {
			player.weak = false;
		}

		lint get_duration() const override {
			return 600;
		}
};

class Bomb: public DurationUseable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.motion = true;
			player.vy = 0;
		}

		void done(Player& player) override {
			player.motion = false;
		}
		lint get_duration() const override { return 100; }
};

class Shield: public DurationUseable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.motion = true;
			player.vy = 0;
		}

		void done(Player& player) override {
			player.motion = false;
		}
		lint get_duration() const override { return 30; }
};

class Potion: public DurationUseable{
	public:
		void use(Player& player) override {
			if(player.rotate) player.rotate = false;
			player.motion = true;
			player.vy = 0;
		}

		void done(Player& player) override {
			player.motion = false;
		}
		lint get_duration() const override { return 150; }
};

class Game{
	private:
		shared_ptr<Player> _player;
		//queue<string> _commands{};
		lint _base_g;

		unordered_map<string, std::tuple<shared_ptr<Useable>, bool>> _actions{
			{"none", {std::make_shared<None>(), false}},
			{"d", {std::make_shared<Dash>(), false}},
			{"aj", {std::make_shared<AirJump>(), false}},
			{"qd", {std::make_shared<QuickDrop>(), false}},
			{"ra", {std::make_shared<RotateAttack>(), false}},
			{"hda", {std::make_shared<HorizontalAttak>(), false}},
			{"ruda", {std::make_shared<UpwardAttack>(), false}},
			{"acc", {std::make_shared<Accelate>(), true}},
			{"gw", {std::make_shared<GravityWeak>(), true}},
			{"bomb", {std::make_shared<Bomb>(), true}},
			{"shield", {std::make_shared<Shield>(), true}},
			{"potion", {std::make_shared<Potion>(), true}}
		};
	public:
		Game(shared_ptr<Player> player, lint base_g, lint init_y)
		:_player(player), _base_g(base_g){
			player->y = init_y;	
		}

		bool update(const std::string key, bool idle){

			if(_player->is_landing()){
				return false;
			}

			{
				_player->set_rotate();
				_player->reduce_dash();
				_player->update();
			}
			if(!idle){
				auto [useable, is_duration] = _actions[key];
				if(is_duration){
					_player->input(
						nullptr, std::static_pointer_cast<DurationUseable>(useable)
					);
				}
				else{
					_player->input(useable, nullptr);
				}
			}
			{
				_player->move_horizontal();
				_player->move_vertical();
			}
			{
				_player->calc_bundle();
			}
			{
				_player->affect_gravity(_base_g);
			}
			return true;
		};
};

int main(){
	lint base_x, jump, maxdrop;
	lint base_g, init_y;
	lint N;
	scanf("%lld %lld %lld", &base_x, &jump, &maxdrop);
	scanf("%lld %lld", &base_g, &init_y);
	scanf("%lld", &N);
	
	shared_ptr<Player> player = std::make_shared<Player>();
	player->base_x = base_x;
	player->jump = jump;
	player->vy = jump;
	player->maxdrop = maxdrop;

	Game game{player, base_g, init_y};

	while(N--){
		char command[10] = { 0, };
		scanf("%s", command);
		game.update(std::string{command}, false);	
	}
	
	bool flag = true;
	while(flag){
		flag = game.update("none", true);
	};

	printf("%lld\n", player->x);

	return 0;
}
