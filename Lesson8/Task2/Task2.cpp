#include "Player.h"
#include "Enemy.h"
#include <vector>





int main()
{
	std::vector<Entity*> entities;
	for (int i = 0; i != 5; ++i)
	{
		entities.push_back(new Player());
		entities.push_back(new Enemy());
	}
	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		Entity* thisOne = *it;
		thisOne->attack();
	}
}