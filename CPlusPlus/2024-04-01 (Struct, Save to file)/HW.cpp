#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

enum MENU{ CHANGE = 1, SHOW, SEARCHA, SEARCHT, SEARCHP, SEARCHG, ADD, SAVE, LOAD };

struct Book
{
private:
	char title[50];
	char author[50];
	char publisher[50];
	char genre[50];
	int yearOfPublication;
	int price;
public:
	void Show()
	{
		cout << "Title : " << title << " ,  Author : " << author << " ,  Publisher : " << publisher << " ,  Genre : " << genre << " ,  Year of publication : " << yearOfPublication << " ,  price : " << price << endl;
	}
};



int Menu()
{
	int choice;
	cout << "1 - change data" << endl;
	cout << "2 - show data" << endl;
	cout << "3 - search by author" << endl;
	cout << "4 - search by title" << endl;
	cout << "5 - search by publisher" << endl;
	cout << "6 - search by genre" << endl;
	cout << "7 - add new book" << endl;
	cout << "8 - save to file" << endl;
	cout << "9 - load from file" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	cout << endl;
	return choice;
}




void AddHuman(Human*& h, int& size)
{
	size++;
	Human* temp = new Human[size];//1
	for (int i = 0; i < size - 1; i++)
	{
		temp[i].Copy(h[i]);
	}
	temp[size - 1].Fill();
	delete h;
	h = temp;
	h[size - 1].SaveToFile();
}




int main()
{
	int size = 0;
	Book* Library = new Book[size];
	
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::CHANGE:
		case MENU::SHOW: for (int i = 0; i < size; i++) (*(Library + i)).Show();
		case MENU::SEARCHA:
		case MENU::SEARCHT:
		case MENU::SEARCHP:
		case MENU::SEARCHG:
		case MENU::ADD:
		case MENU::SAVE:
		case MENU::LOAD:
		}
		cout << endl;
	}
	cout << "Good bye" << endl;
}