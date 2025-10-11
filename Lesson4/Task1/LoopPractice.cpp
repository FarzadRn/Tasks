#include <iostream>

int main()
{
	//1 to 10 while loop
	// do-while input 1-10 - if invalid try again
	//for loop => print first 10(index) multiples of 3 (3-30)
	int numToTen = 0;
	int userInput1to10;
	
	while (numToTen < 10)
	{
		numToTen++;
		std::cout << numToTen << std::endl;
	}
	
	std::cout << std::endl;
	
	do {
		std::cout << "input a number from 1 to 10: " << std::endl;
		std::cin >> userInput1to10;
	} while (userInput1to10 <= 1 || userInput1to10 >= 10);
	
	std::cout << std::endl;
	
	for (int i = 1; i <= 10; i++)
	{
		std::cout << i * 3 << std::endl;
	}
	
	return 0;
}