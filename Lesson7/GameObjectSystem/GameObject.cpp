#include "GameObject.h"



GameObject::GameObject(std::string newName, int newHealth)
	:name(newName)
	,health(newHealth)
{
}
GameObject::~GameObject()
{
	std::cout << "ORE WA DESTROYED!!: " << name << '\n';
}

void GameObject::takeDamage(int damageTaken)
{
	health -= calculateDamageTaken(damageTaken);
}


void GameObject::heal(int healAmount)
{
	health += healAmount;
}

void GameObject::displayInfo()
{
	std::cout << name << " : " << health << '\n';
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
Player::Player(std::string newName, int newHealth)
	:GameObject(newName, newHealth)
{

}

void Player::levelUp()
{

}

void Player::displayInfo()
{
	std::cout<<name<<" : "<<health<<" : "<<expPoints<<'\n';
}