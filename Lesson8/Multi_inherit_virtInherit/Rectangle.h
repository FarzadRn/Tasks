#pragma once
#include "Shape.h"






class Rectangle : virtual public Shape
{
public:
	Rectangle() = default;
	~Rectangle() = default;

	void draw() override
	{
		std::cout << "Rectangle\n";
	}
private:


};