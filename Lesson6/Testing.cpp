#include <iostream>
#include <vector>
struct enemy
{
	std::string name;
	int health = 0;
};

enemy* createEnemy(std::string& name, int health)
{
	enemy* boss = new enemy();
	boss->name = name;
	boss->health = health;
	return boss;

}
void func(enemy* ref)
{
	std::cout << '\n' << "hi" << '\n';
	std::cout << ref->name << '\n';
}

int main()
{
	std::string bossName = "WOLF";
	std::string* bossRefName = &bossName;
	enemy* mainEnemy = createEnemy(*bossRefName, 200);

	std::cout << mainEnemy->name << '\n';
	delete mainEnemy;
	mainEnemy = nullptr;
	if (mainEnemy != nullptr)
	{
		func(mainEnemy);
	}



	//
	enemy* enemy1 = new enemy();
	enemy* enemy2 = new enemy();
	enemy1->name = "BULLY";
	enemy1->health = 20;
	//
	int* I = new int();
	*I = 20;
	int* B = I;
	delete I;
	I = nullptr;
	B = I;
	if (B)
	{
		std::cout << *B << '\n';
	}
	//
	delete I;
	I = nullptr;
	delete enemy1;
	enemy1 = nullptr;
	delete enemy2;
	enemy2 = nullptr;

	//

	std::cout << "//" << '\n';
	int N=2;
	int& ref = N;
	std::cout << ref << '\n';
	std::cout << "//" << '\n';




	//

	if (I != nullptr)
	{
		std::cout << *I << '\n';
	}
	if (enemy1)
	{
		std::cout << (*enemy1).name << '\n';
		std::cout << enemy1->health << '\n';
	}
	if (enemy2 != nullptr)
	{
		std::cout << (*enemy2).name << '\n';
		std::cout << enemy2->health << '\n';
	}

	int a = 100;
	int* b = &a;
	int** c = &b;
	int*** d = &c;
	int**** e = &d;
	int***** f = &e;

	int* a1 = &a;
	int* a2 = a1;
	int* a3 = a2;

	std::cout << " a: " << a << '\n';
	std::cout << "&a: " << &a << '\n';
	std::cout << " b: " << b << '\n';
	std::cout << "&b: " << &b << '\n';
	std::cout << " c: " << c << '\n';
	std::cout << "&c: " << &c << '\n';
	std::cout << " **e: " << **e << '\n';
	std::cout << "****e:" << ****e << '\n';
	std::cout << "//" << '\n';
	std::cout << " a1:" << a1 << '\n';
	std::cout << "&a1:" << &a1 << '\n';
	std::cout << " a2:" << a2 << '\n';
	std::cout << "&a2:" << &a2 << '\n';
	std::cout << "//" << '\n';
	std::cout << "//" << '\n';

	int arr[3] = { 1,3,9 };
	int* arrPointer = &arr[0];
	int* arrPointer1 = &arr[1];
	std::cout << "&arrPointer1: " << &arrPointer1 << '\n';
	std::cout << "*(arrPointer+2): " << *(arrPointer + 2) << '\n';





	return 0;
}
