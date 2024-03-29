#include "Player.h"
#include <string>

string Player::get_name() const {
	return name_;
}

void Player::set_name(string name) {
	this->name_ = name;
}

int Player::get_score() const {
	return score_.get_amount();
}

void Player::update_score(int value) {
	score_.update_amount(value);
}

void Player::set_used_bomb(bool value) {
	used_bomb_ = value;
}

bool Player::has_used_bomb() {
	return used_bomb_;
}