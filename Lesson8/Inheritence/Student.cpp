#include "Student.h"




Student::Student()
{

}
Student::Student (std::string newName, std::string newCourseName, int newAge)
	:age(newAge)
	,courseName(newCourseName)
{
	name = newName;
}
Student::~Student()
{

}

std::string Student::getName()
{
	std::cout << name << " : " << courseName << std::endl;
	std::string output = (name + " : " + courseName);
	return output;
}
