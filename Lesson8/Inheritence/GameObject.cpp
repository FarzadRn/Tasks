#include "GameObject.h"





GameObject::GameObject()
{

}
GameObject::GameObject(std::string newName, int newHealth)
	:name(newName)
	,currentHealth(newHealth)
	,maxHealth(newHealth)
{

}
GameObject::~GameObject()
{
	std::cout << name << " Destroyed!" << std::endl;
}

void GameObject::displayInfo()
{
	std::cout << name << " : "
		<< currentHealth << "/" << maxHealth 
		<< std::endl;
}
void GameObject::takeDamage(int damageTaken)
{
	if (currentHealth - damageTaken < 0)
	{
		currentHealth = 0;
	}
	else
	{
		currentHealth -= damageTaken;
	}
}
void GameObject::heal(int healAmount)
{
	if (currentHealth + healAmount > maxHealth)
	{
		currentHealth = maxHealth;
	}
	else
	{
		currentHealth += healAmount;
	}

}
