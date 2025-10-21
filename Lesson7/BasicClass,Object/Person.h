#pragma once
#include <string>




class Person
{
public:
	Person(std::string name, int age);
	~Person();

	void printDetails();

private:
	std::string name;
	int age;
};