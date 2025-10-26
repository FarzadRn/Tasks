#pragma once
#include <iostream>








class Entity
{
public:
	Entity();
	~Entity();
	virtual int attack() = 0;



protected:
	float currentHealth = 100;
	float maxHealth = 100;
	float damage = 15;




};