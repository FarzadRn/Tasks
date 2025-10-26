#include "GameObject.h"
#include "Player.h"
#include "Student.h"



int main()
{
	Player me("Batman", 160);
	std::string outPut = me.getName();

	std::cout << "\n===========++++++++++++++===========\n\n";

	Player* superman = new Student("super","JL", 200);
	superman->getName();
	Player ironman = Student();

	std::cout << std::endl;
	std::cout << std::endl;
	ironman.getName();

	std::cout << std::endl;
	return 0;
}