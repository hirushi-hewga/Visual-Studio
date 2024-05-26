#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int p) {
	COORD coord;
	coord.X = p;
	coord.Y = p;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



template<typename T>
struct Node
{
	Node* prev;
	T* food;
	Node* next;
	Node(Node* prev, T* food, Node* next) : prev(prev), food(food), next(next) {}
};
template<typename T>
class List
{
	Node<T>* head;
	Node<T>* tail;
public:
	List() : head(nullptr), tail(nullptr) {}

	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(T* food)
	{
		if (IsEmpty())
		{
			Node<T>* newNode = new Node<T>(nullptr, food, nullptr);
			head = tail = newNode;
		}
		else
		{
			Node<T>* newNode = new Node<T>(nullptr, food, head);
			head = head->prev = newNode;
		}
	}
	void AddToTail(T* food)
	{
		if (IsEmpty())
		{
			Node<T>* newNode = new Node<T>(nullptr, food, nullptr);
			head = tail = newNode;
		}
		else
		{
			Node<T>* newNode = new Node<T>(tail, food, nullptr);
			tail = tail->next = newNode;
		}
	}
	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			system("cls");
			gotoxy(0);
			cout << "Error! List is empty." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
		{
			delete head->food;
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev->food;
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty())
		{
			system("cls");
			gotoxy(0);
			cout << "Error! List is empty." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
		{
			delete tail->food;
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next->food;
			delete tail->next;
			tail->next = nullptr;
		}
	}

	~List()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}
};



class Pizza
{
	string recipe;
public:
	Pizza(string recipe) : recipe(recipe) {}
	virtual void PreparePizza()const = 0;
};

class MilanPizza : public Pizza
{
	void PreparePizza()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Milan pizza prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	MilanPizza(string recipe) : Pizza(recipe) { PreparePizza(); }
};
class GreecePizza : public Pizza
{
	void PreparePizza()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Greece pizza prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	GreecePizza(string recipe) : Pizza(recipe) { PreparePizza(); }
};



class Souce
{
	string recipe;
public:
	Souce(string recipe) : recipe(recipe) {}
	virtual void PrepareSouce()const = 0;
};

class MilanSouce : public Souce
{
	void PrepareSouce()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Milan souce prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	MilanSouce(string recipe) : Souce(recipe) { PrepareSouce(); }
};
class GreeceSouce : public Souce
{
	void PrepareSouce()const override
	{
		system("cls");
		gotoxy(0);
		cout << "Greece souce prepared" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
public:
	GreeceSouce(string recipe) : Souce(recipe) { PrepareSouce(); }
};



class Fabric
{
public:
	virtual Pizza* PreparePizza(string recipe)const = 0;
	virtual Souce* PrepareSouce(string recipe)const = 0;
};

class FabricMilan : public Fabric
{
public:
	Pizza* PreparePizza(string recipe)const override
	{
		return new MilanPizza(recipe);
	}
	Souce* PrepareSouce(string recipe)const override
	{
		return new MilanSouce(recipe);
	}
};
class FabricGreece : public Fabric
{
public:
	Pizza* PreparePizza(string recipe)const override
	{
		return new GreecePizza(recipe);
	}
	Souce* PrepareSouce(string recipe)const override
	{
		return new GreeceSouce(recipe);
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 5)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		cout << "1 - Prepare Milan pizza" << endl;
		cout << "2 - Prepare Milan souce" << endl;
		cout << "3 - Prepare Greece pizza" << endl;
		cout << "4 - Prepare Greece souce" << endl;
		cout << "5 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { MILAN_PIZZA = 1, MILAN_SOUCE, GREECE_PIZZA, GREECE_SOUCE, EXIT };
int main()
{
	int choice = 0;
	bool isValidData = true;
	List<Pizza> listMP;
	List<Souce> listMS;
	List<Pizza> listGP;
	List<Souce> listGS;
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::MILAN_PIZZA:
			system("cls");
			gotoxy(0);
			while (choice < 1 || choice > 2)
			{
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "1 - Add to begin" << endl;
				cout << "2 - Add to end" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			isValidData = true;
			choice = 0;
			break;
		case MENU::MILAN_SOUCE:
			break;
		case MENU::GREECE_PIZZA:
			break;
		case MENU::GREECE_SOUCE:
			break;
		case MENU::EXIT: isExit = true;
		}
	}
	system("cls");
	gotoxy(0);
	cout << "Good bye." << endl;
}