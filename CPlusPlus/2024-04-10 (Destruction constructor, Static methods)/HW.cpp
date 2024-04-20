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
	Abonent(string name, string surname, string lastname) : Abonent()
	{
		fullname.SetName(name);
		fullname.SetSurname(surname);
		fullname.SetLastname(lastname);
	}
	Abonent(string name, string surname, string lastname, int homePhone, int workPhone, int cellphone) : Abonent(name, surname, lastname)
	{
		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->cellphone = cellphone;
	}
	



	string GetName()
	{
		return fullname.GetName();
	}
	string GetSurname()
	{
		return fullname.GetSurname();
	}
	string GetLastname()
	{
		return fullname.GetLastname();
	}
	int GetHomePhone()
	{
		return homePhone;
	}
	int GetWorkPhone()
	{
		return workPhone;
	}
	int GetCellphone()
	{
		return cellphone;
	}
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
	
	
	
	
	void Show()
	{
		cout << endl;
		if (countAbonents != 0)
		{
			for (int i = 0; i < countAbonents; i++)
			{
				cout << "------ Abonent " << i + 1 << " -------" << endl;
				cout << "Full name : " << abonents[i].GetName() << ' ' << abonents[i].GetSurname() << ' ' << abonents[i].GetLastname() << endl;
				cout << "Home phone : " << abonents[i].GetHomePhone() << endl;
				cout << "Work phone : " << abonents[i].GetWorkPhone() << endl;
				cout << "Cellphone : " << abonents[i].GetCellphone() << endl;
			}
		}
		else cout << "Abonents not found." << endl;
	}
	void Add()
	{
		cout << endl;
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 2)
		{
			if (!isValidData) cout << "Error choice. Try again!" << endl;
			isValidData = false;
			cout << "1 - Total fill abonent" << endl;
			cout << "2 - Fill by full name" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		Abonent* temp = new Abonent[countAbonents + 1];
		for (int i = 0; i < countAbonents; i++)
		{
			temp[i] = abonents[i];
		}
		if (choice == 2)
		{
			string name, surname, lastname;
			cout << "Enter name : "; cin >> name;
			cout << "Enter surname : "; cin >> surname;
			cout << "Enter lastname : "; cin >> lastname;
			temp[countAbonents] = Abonent(name, surname, lastname);
		}
		if (choice == 1)
		{
			string name, surname, lastname;
			int homePhone, workPhone, cellphone;
			cout << "Enter name : "; cin >> name;
			cout << "Enter surname : "; cin >> surname;
			cout << "Enter lastname : "; cin >> lastname;
			cout << "Enter homePhone : "; cin >> homePhone;
			cout << "Enter workPhone : "; cin >> workPhone;
			cout << "Enter cellphone : "; cin >> cellphone;
			temp[countAbonents] = Abonent(name, surname, lastname, homePhone, workPhone, cellphone);
		}
		if (abonents != nullptr) delete[] abonents;
		abonents = temp;
		countAbonents++;
	}




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
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::SHOW_ALL: abonents.Show(); break;
		case MENU::SHOW_BY_FULLNAME:  break;
		case MENU::ADD: abonents.Add(); break;
		case MENU::DELETE:  break;
		case MENU::LOAD_FROM_FILE:  break;
		case MENU::EXIT: isExit = true; break;
		}
		cout << "========================" << endl;
	}
	cout << "Good bye." << endl;
}