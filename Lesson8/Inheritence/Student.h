#pragma once
#include "Player.h"




class Student : public Player
{
public:
	Student();
	Student(std::string newName, std::string newCourseName, int newAge);
	~Student();

	virtual std::string getName() override;
private:
	std::string courseName = "CGS";
	int age = 25;

};