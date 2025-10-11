#include <iostream>
#include <vector>
#include <list>

int main()
{
	srand(time(NULL));
	std::vector<int> vec;
	std::list<int> liste;
	
	for (int i = 0; i != 10; i++)
	{
		vec.push_back(rand()% 100 + 1);
		liste.push_back(vec[i]);
	}

	// -------------------- vector --------------------

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << '\n';
		
	}
	std::cout << "doubling values: " << '\n';

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		*it *= 2;
		std::cout << *it << '\n';
	}
	std::cout << "list with same values as the vector: " << '\n';

	// --------------------- list ---------------------

	for (std::list<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		std::cout << *it << '\n';

	}
	std::cout << "doubling values: " << '\n';

	for (std::list<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		*it *= 2;
		std::cout << *it << '\n';
	}
}