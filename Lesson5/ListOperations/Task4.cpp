#include <iostream>
#include <list>

void printList(std::list<int> lost)
{
	for (std::list<int>::iterator it = lost.begin(); it != lost.end(); it++)
	{
		std::cout << *it << '\n';
	}
}

int main()
{
	srand(time(NULL));
	std::list<int> liste;
	std::cout << "-----------------push back 10 random nums----------------------" << '\n';
	for (int i = 0; i != 10; i++)
	{
		liste.push_back(rand()%10 +1);
	}
	printList(liste);

	std::cout << "-----------------add 0 to each end----------------------" << '\n';
	liste.push_back(0);
	liste.push_front(0);
	printList(liste);

	std::cout << "----------------remove even numbers-------------------------" << '\n';
	for (std::list<int>::iterator it = liste.begin(); it != liste.end();)
	{
		if ((*it % 2) == 0)
		{
			it = liste.erase(it);
		}
		else
		{
			it++;
		}
	}
	printList(liste);
}