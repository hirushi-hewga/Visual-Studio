#include "Header.h"
#include <chrono>


enum DIRECTION { LEFT, RIGHT, UP, DOWN };
class Hero
{
	string name;
	int hp;
	int h, w;
	COORD position;
	char symbol;
	DIRECTION dir;

	void Print(char filler)const
	{
		for (int i = 0; i < h; i++)
		{
			SetCursorPosition(position.X, position.Y + i);
			for (int i = 0; i < w; i++)
			{
				cout << filler;
			}
			cout << endl;
		}
	}
public:
	Hero() : name("no name"), hp(100), h(1), w(1), position({0, 0}), symbol('#'), dir(RIGHT) {}
	Hero(string name, int h, int w, char s) : name(name), hp(100), position({0, 0}), symbol(s), dir(RIGHT)
	{
		this->h = h >= 1 ? h : 1;
		this->w = w >= 1 ? w : 1;
	}
	void PrintHero()const
	{
		SetConsoleTextAttribute(hConsole, ConsoleColors::DARKMAGENTA);
		Print(symbol);
	}
	void ClearHero()const
	{
		SetConsoleTextAttribute(hConsole, ConsoleColors::CYAN);
		Print(' ');
	}
	void ShowInfo()const
	{
		cout << "---------------- Player [ " << name << " ] | HP : " << hp << " ----------------" << endl;
	}
	void Move(int x, int y)
	{
		switch (dir)
		{
		case DIRECTION::RIGHT: MoveRight(); break;
		case DIRECTION::LEFT: MoveLeft(); break;
		case DIRECTION::UP: MoveUp(); break;
		case DIRECTION::DOWN: MoveDown(); break;
		}
	}
	void MoveRight()
	{
		ClearHero();
		position.X++;
		PrintHero();
	}
	void MoveLeft()
	{
		ClearHero();
		position.X--;
		PrintHero();
	}
	void MoveUp()
	{
		ClearHero();
		position.Y--;
		PrintHero();
	}
	void MoveDown()
	{
		ClearHero();
		position.Y++;
		PrintHero();
	}
};



int main()
{
	Hero hero("King", 3, 4, '#');
	hero.ShowInfo();
	hero.Move(10, 10);
	hero.PrintHero();
	time_t interval = 100;
	time_t start = clock();
	while (true)
	{
		if (clock() >= start + interval)
		{
			hero.MoveRight();
			start = clock();
		}
		if (_kbhit)
		{
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77: hero.MoveRight(); break;
				case 80: hero.MoveDown(); break;
				case 72: hero.MoveUp(); break;
				case 75: hero.MoveLeft(); break;
				}
			}
		}
	}
}