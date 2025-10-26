#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Position.h"

class ColoredShape : public Rectangle, public Circle, public Position
{
public:
	ColoredShape() = default;
	~ColoredShape() = default;

	void draw() override
	{
		Rectangle::draw();
		Circle::draw();
		std::cout << "colored\n";
	}
private:
	std::string color;

};