#include <iostream>
#include <fstream>



int main()
{
	//load from file
	// => write to file a to z
	// 
	//read from file a to z to char array
	// 
	//write to new file A to Z uppercase_alphabet.txt

	//WRITING THE LOWER CASE
	std::ofstream lowerCaseOut("lowercase_alphabet.txt");
	if (lowerCaseOut.is_open())
	{
		for (int i = 0; i < 26; i++) {
			lowerCaseOut << char(97 + i) << std::endl;
		}

		lowerCaseOut.close();
		std::cout << "alphabet written on file" << std::endl;
	}
	else {
		std::cout << "error in lowerCaseOut" << std::endl;
	}
	//LOWER CASE WRITTEN

	//read the file into an array
	char alphabets[26] = {0};
	int index = 0;
	std::ifstream alphabetIn("lowercase_alphabet.txt");
	if (alphabetIn.is_open())
	{
		while (index < 26 && alphabetIn >> alphabets[index])
		{
			index++;
		}
		alphabetIn.close();
	}
	else
	{
		std::cout << "error in alphabetIn" << std::endl;
	}
	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabets[i] << std::endl;
	}
	//file read, array done

	//change array to uppercase - output to new file
	for (int i = 0; i < 26; i++)
	{
		alphabets[i] = char(65 + i);
	}
	std::ofstream upperCaseOut("uppercase_alphabet.txt");
	if (upperCaseOut.is_open())
	{
		for (int i = 0; i < 26; i++)
		{
			upperCaseOut << alphabets[i] << std::endl;
		}
		upperCaseOut.close();
	}
	else
	{
		std::cout << "error in upperCaseOut" << std::endl;
	}
}