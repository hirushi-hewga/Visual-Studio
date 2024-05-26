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

class Body
{
	string type;
public:
	Body() : type("no type") {}
	Body(string type) : type(type) {}
};
class Wheel
{
	float radius;
public:
	Wheel() : radius(0) {}
	Wheel(float radius) : radius(radius) {}
};
class Engine
{
	int volume;
public:
	Engine() : volume(0) {}
	Engine(int volume) : volume(volume) {}
};
class Door
{
	string color;
public:
	Door() : color("no color") {}
	Door(string color) : color(color) {}
};
class Headlight
{
public:
	enum TYPE { NONE, STANDART, LED };
private:
	TYPE type;
public:
	Headlight() : type(NONE) {}
	Headlight(TYPE type) : type(type) {}
};

class Car
{
	Headlight* lights;
	int lightCount;
	Door* doors;
	int doorCount;
	Engine* engine;
	Wheel* wheels;
	int wheelCount;
	Body* body;
public:
	Car() : lights(nullptr), doors(nullptr), engine(nullptr), wheels(nullptr), body(nullptr), lightCount(0), doorCount(0), wheelCount(0) {}
	

};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
			cout << endl;
		}
		cout << " - Add headlight" << endl;
		cout << " - Add door" << endl;
		cout << " - Create new engine" << endl;
		cout << " - Add wheel" << endl;
		cout << " - Create new body" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU {};
int main()
{
	Car car;
	bool isExit = false;
	while (!isExit)
	{

	}
	system("cls");
	gotoxy(0);
	cout << "Good bye." << endl;
}