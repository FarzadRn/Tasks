#include <iostream>
#include <string>

struct car
{
	std::string make = "Default";
	std::string model = "Default";
	int year = 0;
};
void compareYear(car& one, car& two)
{
	if (one.year > two.year)
	{
		std::cout << one.model << " is newer." << '\n';
	}
	else if (one.year == two.year)
	{
		std::cout << "they are from same year" << '\n';
	}
	else
	{
		std::cout << two.model << " is newer." << '\n';
	}
}
int main()
{
	car* heapCar = new car;
	car* myCar = new car;
	myCar->make = "idk";
	myCar->model = "dunno";
	myCar->year = 2000;


	std::cout << "enter the details of the car: " << '\n';
	std::cout << "make: ";
	std::cin >> heapCar->make;
	std::cout << '\n';
	std::cout << "model: ";
	std::cin >> heapCar->model;
	std::cout << '\n';
	std::cout << "year: ";
	std::cin >> heapCar->year;
	std::cout << '\n';

	std::cout << "make: " << heapCar->make << " model: " << heapCar->model
		<< " year: " << heapCar->year << "." << '\n';


	if (heapCar && myCar)
	{
		compareYear(*heapCar, *myCar);

		delete heapCar;
		heapCar = nullptr;
		delete myCar;
		myCar = nullptr;
	}

	delete myCar;
	myCar = nullptr;
	delete heapCar;
	heapCar = nullptr;

	if (!heapCar)
	{
		std::cout << "pointer for heapCar succesfully taken care of" << '\n';
	}



}