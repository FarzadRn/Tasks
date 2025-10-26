#pragma once
#include "Entity.h"





class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();
	int attack() override;

private:

};