#include "Enemy.h"







Enemy::Enemy()
{
	damage = 20;
}
Enemy::~Enemy()
{

}

int Enemy::attack()
{
	std::cout << "Enemy: " << damage << std::endl;
	return damage;
}