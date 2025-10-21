#include "Car.h"
#include <iostream>

//constructors
Car::Car()
	:m_year(2025)
	,m_miles(1500)
	,m_brand("unspecified")
{
	std::cout << "I'M CREATED!!" << '\n';
}
Car::Car(int year, int miles, std::string brand)
	:m_year(year)
	, m_miles(miles)
	, m_brand(brand)
{
	std::cout << "Constructor called." << '\n';
}
//destructor
Car::~Car()
{
	std::cout << "Destructor called." << '\n';
}

//member functions
void Car::displayCar()
{
	std::cout << "Brand: " << m_brand << '\n';
	std::cout << " Year: " << m_year << '\n';
	std::cout << "miles: " << m_miles << '\n';
}
void Car::drive(int miles)
{
	m_miles += miles;
}



