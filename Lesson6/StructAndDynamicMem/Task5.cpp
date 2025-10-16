#include <iostream>
#include <string>
struct player
{
	std::string name = "default";
	int score = 0;
	player* rival;
};

void swapScores(player& one, player& two)
{
	int temp = one.score;
	one.score = two.score;
	two.score = temp;
}

int main()
{
	player* playerONE = new player;
	player* playerTWO = new player;

	std::cout << "player ONE, enter your name: ";
	std::cin >> playerONE->name;
	std::cout << '\n';
	std::cout << "player ONE, enter your score: ";
	std::cin >> playerONE->score;
	std::cout << '\n';
	std::cout << "player TWO, enter your name: ";
	std::cin >> playerTWO->name;
	std::cout << '\n';
	std::cout << "player TWO, enter your score: ";
	std::cin >> playerTWO->score;
	std::cout << '\n';
	playerONE->rival = playerTWO;
	playerTWO->rival = playerONE;

	if (playerONE != nullptr && playerTWO != nullptr)
	{
		std::cout << playerONE->name << " with score of " << playerONE->score << " vs " << playerONE->rival->name << '\n';
		std::cout << playerTWO->name << " with score of " << playerTWO->score << " vs " << playerTWO->rival->name << '\n';


		swapScores(*playerONE, *playerTWO);
		std::cout << "new scores: " << playerONE->name << ": " << playerONE->score << '\n';
		std::cout << "new scores: " << playerTWO->name << ": " << playerTWO->score << '\n';

		delete playerONE;
		delete playerTWO;
		playerONE = nullptr;
		playerTWO = nullptr;
	}
	delete playerONE;
	delete playerTWO;
	playerONE = nullptr;
	playerTWO = nullptr;
}