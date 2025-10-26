#pragma once
#include <iostream>





class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void interact() = 0;
};