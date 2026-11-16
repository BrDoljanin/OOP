#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(const std::string& ime) : name(ime) {}

void Player::print() const
{

	cout << "igrac: " << name << '\n';
	cout << "Level: Neprijatelja " << level.br_nepr() << ", oruzja" << level.br_oruz();

}
