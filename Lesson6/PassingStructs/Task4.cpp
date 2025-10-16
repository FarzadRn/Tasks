#include <iostream>

struct rectangle
{
	int width = 10;
	int height = 10;
};


void value(rectangle* rec)
{
	rec->width *= 2;
	rec->height += 10;
}
void reference(rectangle& rec)
{
	rec.width *= 3;
	rec.height += 30;
}

rectangle& compareArea(rectangle& a, rectangle& b)
{
	int area1 = a.height * a.width;
	int area2 = b.height * b.width;
	
	std::cout << "if the area is the same I will return nothing." << '\n';
 	if (area1 >= area2)
	{
		std::cout << "area of rectangle a is lorger" << '\n';
		return a;
	}
	else
	{
		std::cout << "area of rectangle b is lorger" << '\n';
		return b;
	}
}

int main()
{
	rectangle* val = new rectangle;
	rectangle ref;
	value(val);
	reference(ref);
	if (val != nullptr)
	{
		compareArea(*val, ref);
		delete val;
		val = nullptr;
	}
}