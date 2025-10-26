#pragma once
#include <iostream>





class Shape
{
public:
	Shape()
	{
		std::cout << "Shape constructed.\n";
	}
	virtual ~Shape() = default;

	virtual void draw() = 0;
private:

};