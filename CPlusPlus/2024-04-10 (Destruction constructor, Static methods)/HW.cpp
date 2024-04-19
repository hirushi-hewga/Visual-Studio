#include <iostream>
using namespace std;

struct Fullname
{
private:
	string name;
	string surname;
	string lastname;
public:
	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	string GetLastname()
	{
		return lastname;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	void SetSurname(string surname)
	{
		this->surname = surname;
	}
	void SetLastname(string lastname)
	{
		this->lastname = lastname;
	}
};




class Abonent
{
	Fullname fullname;
	int homePhone;
	int workPhone;
	int cellphone;
public:
	Abonent()
	{
		fullname.SetName("No name");
		fullname.SetSurname("No surname");
		fullname.SetLastname("No lastname");
		homePhone = 0;
		workPhone = 0;
		cellphone = 0;
	}




	//
};




class AbonentList
{
	int countAbonents;
	Abonent* abonents;
public:
	AbonentList()
	{
		countAbonents = 0;
		abonents = nullptr;
	}




	//




	~AbonentList()
	{
		delete[] abonents;
	}
};




int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		if (!isValidData) cout << "Error choice. Try again!";
		isValidData = false;
		cout << "1 - Show all abonents" << endl;
		cout << "2 - Show abonent by fullname" << endl;
		cout << "3 - Add abonent" << endl;
		cout << "4 - Delete abonent" << endl;
		cout << "5 - Read from file" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW_ALL = 1, SHOW_BY_FULLNAME, ADD, DELETE, LOAD_FROM_FILE, EXIT };
int main()
{
	AbonentList abonents;
	int choice;
	bool isValidData = true;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		while (choice < 1 || choice > 6)
		{
			if (!isValidData) cout << "Error choice. Try again!";
			isValidData = false;
			switch (Menu())
			{
			case MENU::SHOW_ALL:  break;
			case MENU::SHOW_BY_FULLNAME:  break;
			case MENU::ADD:  break;
			case MENU::DELETE:  break;
			case MENU::LOAD_FROM_FILE:  break;
			case MENU::EXIT: isExit = true; break;
			}
		}
		isValidData = true;
		cout << "========================" << endl;
	}
	cout << "Good bye." << endl;
}