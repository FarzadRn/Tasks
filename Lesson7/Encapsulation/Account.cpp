#include "Account.h"


Account::Account()
{
}
Account::~Account()
{
}

void Account::deposit(int amount)
{
	balance += amount;
}
void Account::withdraw(int amount)
{
	balance -= amount;
}

void Account::setBalance(int amount)
{
	balance = amount;
}
void Account::setAccountOwner(std::string name)
{
	accountOwner = name;
}

void Account::checkBalance()
{
	std::string input;
	std::cout << "enter name to check balance: ";
	std::cin >> input;
	if (input == Account::getAccountOwner())
	{
		std::cout << "Balance: " << getBalance() << '\n';
	}
	else
	{
		std::cout << "WRONG INPUT YOU GO JAIL!" << '\n';
	}
}

double Account::getBalance()
{
	return balance;
}
std::string Account::getAccountOwner()
{
	return accountOwner;
}