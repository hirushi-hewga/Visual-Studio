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



class Parts
{
public:
	virtual void ShowInfo()const
	{
		cout << "Info....." << endl;
	}
};

class Wheel : public Parts
{
	float radius;
public:
	Wheel() : radius(0) {}
	Wheel(float radius) : radius(radius) {}

	void ShowInfo()const override
	{
		cout << "radius " << radius << "mm ";
	}
};
class Door : public Parts
{
	string color;
public:
	Door() : color("no color") {}
	Door(string color) : color(color) {}

	void ShowInfo()const override
	{
		cout << color << " color";
	}
};
class Headlight : public Parts
{
public:
	enum TYPE { NONE, STANDART, LED };
private:
	TYPE type;
public:
	Headlight() : type(NONE) {}
	Headlight(TYPE type) : type(type) {}

	void ShowInfo()const override
	{
		switch (type)
		{
		case Headlight::NONE: cout << "none type"; break;
		case Headlight::STANDART: cout << "standart type"; break;
		case Headlight::LED: cout << "LED type"; break;
		}
	}
};

class Body : public Parts
{
	string type;
public:
	Body() : type("no type") {}
	Body(string type) : type(type) {}

	void ShowInfo()const override
	{
		cout << "Type : " << type << endl;
	}
};
class Engine : public Parts
{
	int volume;
public:
	Engine() : volume(0) {}
	Engine(int volume) : volume(volume) {}

	void ShowInfo()const override
	{
		cout << "Volume : " << volume << " sm^3" << endl;
	}
};



struct Node
{
	Node* prev;
	Parts part;
	Node* next;
	Node(Node* prev, Parts part, Node* next) : prev(prev), part(part), next(next) {}
};
class List
{
	Node* head;
	Node* tail;
public:
	List() : head(nullptr), tail(nullptr) {}

	int NodeCount()const
	{
		Node* current = head;
		int i = 0;
		while (current != nullptr)
		{
			i++;
			current = current->next;
		}
		return i;
	}
	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(Parts part, int max)
	{
		if (max > NodeCount())
		{
			if (IsEmpty())
			{
				Node* newNode = new Node(nullptr, part, nullptr);
				head = tail = newNode;
			}
			else
			{
				Node* newNode = new Node(nullptr, part, head);
				head = head->prev = newNode;
			}
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Error! Parts count is max." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void AddToTail(Parts part, int max)
	{
		if (max > NodeCount())
		{
			if (IsEmpty())
			{
				Node* newNode = new Node(nullptr, part, nullptr);
				head = tail = newNode;
			}
			else
			{
				Node* newNode = new Node(tail, part, nullptr);
				tail = tail->next = newNode;
			}
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Error! Parts count is max." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			system("cls");
			gotoxy(0);
			cout << "Error! Parts not found." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
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
			cout << "Error! Parts not found." << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else if (head == tail && head != nullptr)
		{
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void Show()const
	{
		if (head == nullptr)
		{
			cout << "Parts not found!" << endl;
		}
		else
		{
			Node* current = head;
			for (int i = 1; current != nullptr; i++, current = current->next)
			{
				cout << "Rarts " << i << " : with "; current->part.ShowInfo();
				cout << endl;
			}
		}
		cout << endl;
	}

	~List()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}
};



class Car
{
	List lights;
	int lightMaxCount;
	List doors;
	int doorMaxCount;
	Engine* engine;
	List wheels;
	int wheelMaxCount;
	Body* body;
public:
	Car() : engine(nullptr), body(nullptr), lightMaxCount(2), doorMaxCount(4), wheelMaxCount(4) {}
	
	void ShowCarInfo()const
	{
		system("cls");
		gotoxy(0);
		cout << "======== Headlights [" << lights.NodeCount() << "/2] ========" << endl;
		lights.Show();
		cout << "======== Doors [" << doors.NodeCount() << "/4] ========" << endl;
		doors.Show();
		cout << "======== Engine ========" << endl;
		if (engine != nullptr) engine->ShowInfo();
		else cout << "No engine" << endl;
		cout << endl;
		cout << "======== Wheels [" << wheels.NodeCount() << "/4] ========" << endl;
		wheels.Show();
		cout << "======== Body ========" << endl;
		if (body != nullptr) body->ShowInfo();
		else cout << "No body" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
	void AddLight()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 2)
		{
			system("cls");
			gotoxy(0);
			if (!isValidData)
			{
				cout << "Error choice! Try again." << endl;
				cout << endl;
			}
			cout << "1 - Standart" << endl;
			cout << "2 - LED" << endl;
			cout << "Enter light type : ";
			cin >> choice;
		}
		if (choice == 1) lights.AddToTail(Headlight(Headlight::STANDART), lightMaxCount);
		if (choice == 2) lights.AddToTail(Headlight(Headlight::LED), lightMaxCount);
	}
	void DeleteLight()
	{
		lights.DeleteFromTail();
	}
	void AddDoor()
	{
		string color;
		cout << "Enter door color : ";
		cin >> color;
		doors.AddToTail(Door(color), doorMaxCount);
	}
	void DeleteDoor()
	{
		doors.DeleteFromTail();
	}
	void NewEngine()
	{
		float volume;
		cout << "Enter new engine volume (sm^3) : ";
		cin >> volume;
		if (engine != nullptr)
			delete engine;
		engine = new Engine(volume);
		system("cls");
		gotoxy(0);
		cout << "New engine created" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
	void AddWheel()
	{
		float radius;
		cout << "Enter wheel radius : ";
		cin >> radius;
		wheels.AddToTail(Wheel(radius), wheelMaxCount);
	}
	void DeleteWheel()
	{
		wheels.DeleteFromTail();
	}
	void NewBody()
	{
		string type;
		cout << "Enter new body type : ";
		cin >> type;
		if (body != nullptr)
			delete body;
		body = new Body(type);
		system("cls");
		gotoxy(0);
		cout << "New body created" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}

	~Car()
	{
		delete engine;
		delete body;
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 11)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		cout << "1 - Show car info" << endl;
		cout << "2 - Add headlight" << endl;
		cout << "3 - Delete headlight" << endl;
		cout << "4 - Add door" << endl;
		cout << "5 - Delete door" << endl;
		cout << "6 - Create new engine" << endl;
		cout << "7 - Add wheel" << endl;
		cout << "8 - Delete wheel" << endl;
		cout << "9 - Create new body" << endl;
		cout << "10 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW_CAR_INFO = 1, ADD_LIGHT, DELETE_LIGHT, ADD_DOOR, DELETE_DOOR, NEW_ENGINE, ADD_WHEEL, DELETE_WHEEL, NEW_BODY, EXIT };
int main()
{
	Car car;
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::SHOW_CAR_INFO: car.ShowCarInfo(); break;
		case MENU::ADD_LIGHT: car.AddLight(); break;
		case MENU::DELETE_LIGHT: car.DeleteLight(); break;
		case MENU::ADD_DOOR: car.AddDoor(); break;
		case MENU::DELETE_DOOR: car.DeleteDoor(); break;
		case MENU::NEW_ENGINE: car.NewEngine(); break;
		case MENU::ADD_WHEEL: car.AddWheel(); break;
		case MENU::DELETE_WHEEL: car.DeleteWheel(); break;
		case MENU::NEW_BODY: car.NewBody(); break;
		case MENU::EXIT: isExit = true;
		}
	}
	system("cls");
	gotoxy(0);
	cout << "Good bye." << endl;
}