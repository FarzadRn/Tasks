#include <iostream>

int main()
{
	//while loop inpuy !=5
	//if user inputs 10 times "wow you are patient"
	int userInput = 0;
	int NumberOfInputs = 0;

	std::cout << "hey ";
	while (userInput != 5)
	{
		if (NumberOfInputs >= 10)
		{
			std::cout << "wow! you are patient! here is a 10/10 score for you :)" << std::endl;
			break;
		}

		std::cout << "enter any number other than 5!: " << std::endl;
		std::cin >> userInput;
		NumberOfInputs++;
	}

	if (userInput == 5)
	{
		std::cout << "HEY! YOU WEREN'T SUPPOSED TO ENTER 5!! you get 0/10!" << std::endl;
	}

	return 0;
}