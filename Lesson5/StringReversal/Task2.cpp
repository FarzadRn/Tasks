#include <iostream>
#include <string>


int main()
{
	std::string inputText;
	std::string outputText;
	std::cout << "say something and I will reverse it for you :P :  " << '\n';

	std::getline(std::cin, inputText);
	int addressIndex = 0;
	while (true)
	{
		if (inputText.rfind(' ') == std::string::npos)
		{
			outputText.append(inputText);
			break;
		}

		outputText.append(inputText.substr(inputText.rfind(' ') + 1));
		outputText.push_back(' ');
		inputText.erase(inputText.rfind(' '));

	}
	std::cout << '\n' << outputText;
}