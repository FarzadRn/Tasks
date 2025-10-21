#include "Book.h"
#include <iostream>

Book::Book(std::string Title, std::string Author, int Pages)
	:title(Title)
	,author(Author)
	,pages(Pages)
{

}
Book::~Book()
{
	std::cout << "Destructor is called." << '\n';
}

void Book::displayDetails()
{
	std::cout << "Title: " << title << '\n';
	std::cout << "Author: " << author << '\n';
	std::cout << "Pages: " << pages << '\n';
}