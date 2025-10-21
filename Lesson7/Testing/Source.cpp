#include <iostream>
#include "Car.h"



int main()
{
	//stack
	int* testPointer = nullptr;
	{
		Car myCar(2021, 1000, "Benz");
		testPointer = &myCar.m_year;
		myCar.displayCar();
		std::cout << "------------" << '\n';
		std::cout << "stored in stack: " << '\n' << *testPointer << '\n';
		std::cout << "------------" << '\n';
		std::cout << "Where am I? relative to DESTRUCTOR?" << '\n';
	}
	//garbage random data
	auto a = 1.0f, b = 2.0f, c = 3.0f, d = 4.0f, e = 5.0f
		, f = 6.0f, g = 7.0f, h = 8.0f, i = 9.0f, j = 10.0f;
	int m = 0, n = 11, v = 10, x = 9, z = 8, l = 7, k = 6, s = 4, p = 3, u = 2, y = 1;
	int bob[180000];
	//garbage------------
	std::cout << "------------" << '\n';
	std::cout << "initilized in stack: " << '\n';
	std::cout << *testPointer << '\n';
	std::cout << "------------" << '\n';

	//heap
	int* pointTester2 = nullptr;
	{
		std::cout << "=====================================" << '\n';
		Car* ptrCar = new Car(1500, 20, "OLD");
		pointTester2 = &ptrCar->m_year;
		ptrCar->displayCar();

		delete ptrCar;
		std::cout << "Where am I? relative to DESTRUCTOR?" << '\n';
		ptrCar = nullptr;

	}
	std::cout << "------------" << '\n';
	std::cout << "stored in heap: ";
	std::cout << *pointTester2 << '\n';
	std::cout << "------------" << '\n';
	std::cout << "initilized in stack: " << '\n';
	std::cout << *testPointer << '\n';

}