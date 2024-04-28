#include "Library.h"

Library::Library()
{
	address = "no address";
	books = nullptr;
	countBooks = 0;
}

Library::Library(string address)
{
	this->address = address;
	books = nullptr;
	countBooks = 0;
}

Library::Library(const Library& other)
{
	this->address = other.address;
	this->countBooks = other.countBooks;
	this->books = new Book[countBooks];
	for (int i = 0; i < countBooks; i++)
	{
		books[i] = other.books[i];
	}
	cout << "--- Copy constructor ---" << endl;
}

void Library::Show() const
{
	cout << "Address : " << address << endl;
	for (int i = 0; i < countBooks; i++)
	{
		books[i].ShowInfo();
		cout << endl;
	}
}

void Library::AddBook(Book book)
{
	Book* temp = new Book[countBooks + 1];
	for (int i = 0; i < countBooks; i++)
	{
		temp[i] = books[i];
	}
	temp[countBooks] = book;
	if (books != nullptr)
		delete[] books;
	books = temp;
	countBooks++;
}

Library::~Library()
{
	if (books != nullptr)
		delete[] books;
}
