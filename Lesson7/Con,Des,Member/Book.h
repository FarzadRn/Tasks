#pragma once
#include <string>

class Book
{
public:
	Book(std::string title, std::string author, int pages);
	~Book();

	void displayDetails();
private:
	std::string title;
	std::string author;
	int pages;
};