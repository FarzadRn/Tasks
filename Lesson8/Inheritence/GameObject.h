#pragma once
#include <iostream>



class GameObject
{
public:	
	GameObject();
	GameObject(std::string newName, int newHealth);
	~GameObject();

	virtual void displayInfo();
	void takeDamage(int damageTaken);
	void heal(int healAmount);
public:
	std::string name = "DEFAULT";
	int maxHealth = 100;
	int currentHealth = 100;
};