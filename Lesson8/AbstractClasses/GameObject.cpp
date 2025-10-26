#include "GameObject.h"








GameObject::GameObject()
{

}
GameObject::~GameObject()
{
	std::cout << "Object getting destroyed.\n";
}

void GameObject::interact()
{
	std::cout << "GameObject interacted.\n";
}