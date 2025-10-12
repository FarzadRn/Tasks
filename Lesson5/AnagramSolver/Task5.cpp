#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	
	std::ifstream inDict("dictionary.txt");
	if (inDict.is_open())
	{
		std::vector<std::string> correctAnswers;
		int correctCycles = 0;
		char anagram[11] = { 'g','i','m','n','o','p','r','g','a','m','r' };
		char buffer[12];
		while (inDict.getline(buffer, 12))
		{
			std::string answer = buffer;
			for (int i = 0; i != 12; i++)
			{
				for (int j = 0; j != 11; j++)
				{
					if (buffer[i] == anagram[j])
					{
						correctCycles++;
						buffer[i] = 'x';
					}
				}
			}
			if (correctCycles >= 10)
			{
				correctAnswers.push_back(answer);
				std::cout << "answer: " << answer << '\n';
				std::cout << "---------------------" << '\n';
			}
			correctCycles = 0;
		}
		inDict.close();
	}
}