#pragma once
#include <iostream>
#include <string>


class GameObject
{
public:
	GameObject(std::string newName, int newHealth);
	~GameObject();

	void takeDamage(int damageTaken);
	void heal(int healAmount);
	
	virtual void displayInfo();



public:
	float calculateDamageTaken(int damageTaken)
	{
		return damageTaken * ((100.0f - armor) / 100.0f);
	}
	std::string name = "Unspecified";
	int health = 100;
	int healthRegen = 1;
	int armor = 20;
	int damage = 15;
	int damageMultiplier = 1;

};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
class Player : public GameObject
{
public:
	Player(std::string newName, int newHealth);

	void levelUp();
	void displayInfo() override;
private:
	double expPoints = 0.0f;
};