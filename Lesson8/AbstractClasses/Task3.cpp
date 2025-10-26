#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include <vector>



int main()
{
	std::vector<GameObject*> collection;
	collection.push_back(new Player());
	collection.push_back(new Enemy());
	collection.push_back(new Item());
	collection.push_back(new Weapon());

	for (std::vector<GameObject*>::iterator it = collection.begin(); it != collection.end(); ++it)
	{
		GameObject* current = *it;

		current->interact();
	}
	//for (std::vector<GameObject*>::iterator it = collection.begin(); it != collection.end();++it)
	{

		//delete *it;
	}
	for (GameObject*& current : collection)
	{
		delete current;
	}
	collection.clear();
	std::cout << collection.size();
	return 0;
}