#include "Player.h"







Player::Player()
{
	damage = 10;
}
Player::~Player()
{

}

int Player::attack()
{
	std::cout << "Player: " << damage << std::endl;
	return damage;
}