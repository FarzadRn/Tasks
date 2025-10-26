#include "Player.h"



Player::Player()
{

}
Player::Player(std::string newName, int newHealth)
{
	name = newName;
	maxHealth = newHealth;
	currentHealth = newHealth;
	std::cout << "I'm batman\n";
}
Player::~Player()
{
	std::cout << name << " Destroyed!" << std::endl;
}


void Player::displayInfo()
{
	GameObject::displayInfo();
	std::cout << "Level: " << level
		<< "\nExp points: " << exp << "/" << "1000"
		<< "\nDamage: " << damage;
}
std::string Player::getName()
{
	std::cout << name << " : " << currentHealth << "/" << maxHealth << std::endl;
	return name;
}

void Player::levelUp()
{
	
}