#include <iostream>


int main()
{
	int arrStack[5];
	int* arrHeap = new int[5];

	std::cout << "enter 5 numbers for stack: " << '\n';
	for (int i = 0; i != 5; ++i)
	{
		int input;
		std::cin >> input;
		arrStack[i] = input;
	}
	std::cout << "printing: " << '\n';
	for (int i = 0; i != 5; ++i)
	{
		std::cout << arrStack[i] << '\n';
	}
	if (arrHeap != nullptr)
	{
		std::cout << "enter 5 numbers for Heap: " << '\n';
		for (int i = 0; i != 5; ++i)
		{
			int input;
			std::cin >> input;

			arrHeap[i] = input;
		}
		std::cout << "printing: " << '\n';
		for (int i = 0; i != 5; ++i)
		{
			std::cout << arrHeap[i] << '\n';
		}

		delete arrHeap;
		arrHeap = nullptr;
	}
}