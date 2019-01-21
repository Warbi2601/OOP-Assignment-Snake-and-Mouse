#include "Bomb.h"

Bomb::Bomb() : MoveableGridItem('B', 0, 0)
{
}

void Bomb::reset() {
	time_ = 3;
	active_ = false;
}

int Bomb::get_time() {
	return time_;
}

int Bomb::tick()
{
	return time_--;
}

bool Bomb::has_exploded() {
	return time_ <= 0;
}

bool Bomb::is_active() {
	return active_;
}

void Bomb::set_active(bool value) {
	active_ = value;
}

void Bomb::set_time(int time) {
	time_ = time;
}