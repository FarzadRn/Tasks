#pragma once
#include "GameObject.h"


class Player : public GameObject
{
public:
	Player();
	Player(std::string newName, int newHealth);
	~Player();

	virtual void displayInfo() override; 
	virtual std::string getName();

private:
	float exp = 15;
	void levelUp();
	int level = 1;

	int damage = 50;
};