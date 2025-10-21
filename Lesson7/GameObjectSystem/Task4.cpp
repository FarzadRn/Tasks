#include "GameObject.h"



int main()
{
	GameObject GO("myGo", 100);
	Player player("myPlayer", 50);

	std::cout << "Game Object: " << '\n';
	GO.displayInfo();
	std::cout << '\n';

	std::cout << "Player: " << '\n';
	player.displayInfo();
	std::cout << '\n';

	std::cout << '\n';

	player.heal(360);
	player.displayInfo();

	std::cout << '\n';

	player.takeDamage(400);
	std::cout << "after taking 400 damage: " << '\n';

	player.displayInfo();
}