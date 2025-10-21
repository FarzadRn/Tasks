#pragma once
#include <iostream>


class Account
{
public:
	Account();
	~Account();

	void deposit(int amount);
	void withdraw(int amount);

	void setBalance(int amount);
	void setAccountOwner(std::string name);

	void checkBalance();

	double getBalance();
	std::string getAccountOwner();
private:
	double balance;
	std::string accountOwner;
};