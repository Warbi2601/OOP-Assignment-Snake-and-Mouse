#include "Player.h"
#include <iostream>

string Player::get_name() const {
	return name_;
}

void Player::set_name() {
	cout << "Enter your name: ";
	cin >> name_;
}

int Player::get_score() const {
	return score_.get_amount();
}

void Player::update_score(int value) {
	score_.update_amount(value);
}