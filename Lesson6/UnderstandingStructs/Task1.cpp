#include <iostream>
#include <string>
struct person
{
	std::string name = "Default";
	int age = 0;
	float height = 0.0f;
	int* pointer = new int[10000000]();//without 48 // with 56
};


person* factory(const std::string& name, int age, int height)
{
	person* pPtr = new person;
	pPtr->name = name;
	pPtr->age = age;
	pPtr->height = height;
	pPtr->pointer[200] = 5;
	return pPtr;
}

int main()
{
	person* worker1 = factory("john", 12, 230.0f);
	person* worker2 = factory("babo", 21, 510.0f);
	
	std::cout << "size of worker1: " << sizeof(*worker1) << '\n';
	std::cout << "size of worker2: " << sizeof(*worker2) << '\n';
	std::cout << '\n' << "pointer 200: " << worker1->pointer[200] << '\n';

}