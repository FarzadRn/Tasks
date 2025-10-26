#pragma once
#include "Shape.h"






class Circle : virtual public Shape
{
public:
	Circle() = default;
	~Circle() = default;

	void draw() override
	{
		std::cout << "Circle\n";
	}
private:


};