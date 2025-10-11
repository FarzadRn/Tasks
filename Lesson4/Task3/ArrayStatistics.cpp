#include <iostream>
#include <vector>
struct evenOdds
{
	int evens;
	int odds;
};
struct  allReturnedValues
{
	long long sumOfAll;
	long long averageOfNums;
	int largestNum;
	int smallestNum;
	int quantityOfEvens;
	int quantityOfOdds;
};

void takeUserInputs(std::vector<long long>& inputNums)
{
	int input;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "please enter num " << i + 1 << " of 10 numbers: ";
		std::cin >> input;
		inputNums.push_back(input);
	}
	return;
}

long long sumAll(std::vector<long long>& numbers)
{
	long long sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum = sum + numbers[i];
	}
	return sum;
}

long long averageOfNums(long long sumOfAll, std::vector<long long>& numbers)
{
	return (sumOfAll / numbers.size());
}

int findLargest(int largestNum, int index, std::vector<long long>& numbers)
{
	if (index >= numbers.size()-1) return largestNum;

	if (numbers[index] > numbers[index + 1] && numbers[index] > largestNum)
	{
		largestNum = numbers[index];
	}
	index++;
	findLargest(largestNum, index, numbers);
}
int findSmallest(int smallestNum, int index, std::vector<long long>& numbers)
{
	if (index >= numbers.size() - 1) return smallestNum;

	if (numbers[index] < numbers[index + 1] && numbers[index] < smallestNum)
	{
		smallestNum = numbers[index];
	}
	index++;
	findSmallest(smallestNum, index, numbers);
}

evenOdds evensAndoddsQuantity(std::vector<long long>& numbers)
{
	int evens = 0;
	int odds = 0;
	
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 2)
		{
			odds++;
		}
		else
		{
			evens++;
		}
	}
	return { evens,odds };
}

allReturnedValues handleAllCalculations(std::vector<long long> numbers)
{
	const int indexZero = 0;

	long long sum = sumAll(numbers);
	long long average = averageOfNums(sum, numbers);
	int largest = findLargest(numbers[0], indexZero, numbers);
	int smallest = findSmallest(numbers[0], indexZero, numbers);
	int quantityEvens = evensAndoddsQuantity(numbers).evens;
	int quantityOdds = evensAndoddsQuantity(numbers).odds;

	return{ sum,average,largest,smallest,quantityEvens,quantityOdds };
}
int main()
{
	//input 10 ints
	//store in arr
	//print content of arr
	//sum of all/average/largetst,smallest/quant of even and odd
	//bonus-
	//modify to handle 20 - vector?
	//repeat code

	allReturnedValues values;
	const int INITIALIZER = 0;
	std::vector<long long> numbers;
	bool isRepeating = false;
	int userInput;

	std::cout << "this program you are asked to write 10 ints then 20, so for the first part please write 10 ints." << std::endl;
	takeUserInputs(numbers);
	do
	{
		values = handleAllCalculations(numbers);
		std::cout << "sum of nums: " << values.sumOfAll << std::endl;
		std::cout << "average of nums: " << values.averageOfNums << std::endl;
		std::cout << "largest num: " << values.largestNum << std::endl;
		std::cout << "smallest num: " << values.smallestNum << std::endl;
		std::cout << "number of evens: " << values.quantityOfEvens << std::endl;
		std::cout << "number of odds: " << values.quantityOfOdds << std::endl;

		std::cout << "would you like to try 10 more numbers? press 1 for yes and 0 for no: \n";
		std::cin >> isRepeating;
		if (isRepeating)
		{
			takeUserInputs(numbers);
		}
	} while (isRepeating);
	

}