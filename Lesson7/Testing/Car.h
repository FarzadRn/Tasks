#pragma once
#include <string>
class Car
{
public:
	//constructors
	Car();
	Car(int year, int miles, std::string brand);
	
	//destructor
	~Car();
	
	//member functions
	void displayCar();
	void drive(int miles);

public:
	int m_year;
	int m_miles;
	std::string m_brand;

};