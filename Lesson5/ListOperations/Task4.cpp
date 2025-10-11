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

	for (int i = 0; i != 10; i++)
	{
		liste.push_back(rand()%10 +1);
	}
	printList(liste);
	std::cout << "---------------------------------------" << '\n';

	//add element to front and back of list: 
	liste.push_back(0);
	liste.push_front(0);
	printList(liste);
	std::cout << "---------------------------------------" << '\n';
	//remove all even numbers
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

	//
}