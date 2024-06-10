#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>
using namespace std;

enum ConsoleColors {
	BLACK = 0,
	DARKBLUE = FOREGROUND_BLUE,
	DARKGREEN = FOREGROUND_GREEN,
	DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKRED = FOREGROUND_RED,
	DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRAY = FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetCursorPosition(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, pos);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

enum DIRECTION { LEFT, RIGHT, UP, DOWN };

class Hero
{
	int w, h;
	COORD position;
	char symbol;
	DIRECTION dir;
public:
	Hero() : h(15), w(30), position({ 1, 1 }), symbol((char)178), dir(RIGHT) {}

	void PrintSymbol()const
	{

	}
	void PrintBord()const
	{
		COORD pos{ 0, 0 };
		SetCursorPosition(pos.X, pos.Y);
		cout << (char)201;
		for (int i = 0; i < 54; i++)
			cout << (char)205;
		cout << (char)187;
		for (int i = 0; i < 24; i++)
		{
			pos.Y++;
			SetCursorPosition(pos.X, pos.Y);
			cout << (char)186;
			SetCursorPosition(pos.X + 55, pos.Y);
			cout << (char)186;
		}
		pos.Y++;
		SetCursorPosition(pos.X, pos.Y);
		cout << (char)200;
		for (int i = 0; i < 54; i++)
			cout << (char)205;
		cout << (char)188;
	}
	void MarkHero()const
	{
		SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
		for (int i = 0; i < h; i++)
		{
			SetCursorPosition(position.X, position.Y + i);
			for (int i = 0; i < w; i++)
			{
				cout << symbol;
			}
		}
	}
	void PrintHero()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X + 12, pos.Y);
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 4; i++) cout << symbol;
		for (int i = 0; i < 2; i++)
		{
			SetCursorPosition(pos.X + 10, ++pos.Y);
			for (int i = 0; i < 2; i++) cout << symbol;
			SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
			for (int i = 0; i < 4; i++) cout << symbol;
			SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
			for (int i = 0; i < 2; i++) cout << symbol;
		}
		SetCursorPosition(pos.X + 8, ++pos.Y);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 8; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;

		SetCursorPosition(pos.X + 8, ++pos.Y);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetCursorPosition(pos.X + 24, pos.Y);
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 4; i++) cout << symbol;

		SetCursorPosition(pos.X + 6, ++pos.Y);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetCursorPosition(pos.X + 22, pos.Y);
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::DARKGRAY);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;

		SetCursorPosition(pos.X + 6, ++pos.Y);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
		for (int i = 0; i < 4; i++) cout << symbol;
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;
		SetCursorPosition(pos.X + 24, pos.Y);
		SetConsoleTextAttribute(hConsole, ConsoleColors::GRAY);
		for (int i = 0; i < 2; i++) cout << symbol;
	}
	void ClearHero()const
	{
		for (int i = 0; i < h; i++)
		{
			SetCursorPosition(position.X, position.Y + i);
			for (int i = 0; i < w; i++)
			{
				cout << ' ';
			}
		}
	}
	void Move()
	{
		ClearHero();
		bool isMoved = false;
		switch (dir)
		{
		case LEFT: isMoved = MoveLeft(); break;
		case RIGHT: isMoved = MoveRight(); break;
		case UP: isMoved = MoveUp(); break;
		case DOWN: isMoved = MoveDown();
		}
		isMoved ? PrintHero() : MarkHero();
	}
	bool IsValidPosition(int x, int y)const
	{
		return x > 0 && y > 0 && x + w - 1 < 55 && y + h - 1 < 25;
	}
	bool MoveRight()
	{
		if (IsValidPosition(position.X + 1, position.Y))
		{
			position.X++;
			return true;
		}
		return false;
	}
	bool MoveLeft()
	{
		if (IsValidPosition(position.X - 1, position.Y))
		{
			position.X--;
			return true;
		}
		return false;
	}
	bool MoveUp()
	{
		if (IsValidPosition(position.X, position.Y - 1))
		{
			position.Y--;
			return true;
		}
		return false;
	}
	bool MoveDown()
	{
		if (IsValidPosition(position.X, position.Y + 1))
		{
			position.Y++;
			return true;
		}
		return false;
	}
	void ChangeDirection(DIRECTION dir)
	{
		this->dir = dir;
	}
};



int main()
{
	hidecursor();
	Hero hero;
	hero.PrintBord();

	time_t interval = 100;
	time_t start = clock();

	while (true)
	{
		if (clock() >= start + interval)
		{
			hero.Move();
			start = clock();
		}
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77: hero.ChangeDirection(RIGHT); break;
				case 80: hero.ChangeDirection(DOWN); break;
				case 72: hero.ChangeDirection(UP); break;
				case 75: hero.ChangeDirection(LEFT); break;
				}
			}
		}
	}
}
