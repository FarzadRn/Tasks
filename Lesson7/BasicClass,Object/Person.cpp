#include "Person.h"
#include <iostream>


Person::Person(std::string Name, int Age)
	:name(Name)
	,age(Age)
{

}

Person::~Person()
{
	std::cout << "Destructor called." << '\n';
}

void Person::printDetails()
{
	std::cout << name << " is " << age << " years old." << '\n';
}