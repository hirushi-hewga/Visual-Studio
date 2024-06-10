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
	Hero() : h(1), w(1), position({ 1, 1 }), symbol((char)178), dir(RIGHT) {}

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
		for (int i = 0; i < h; i++)
		{
			SetCursorPosition(position.X, position.Y + i);
			for (int i = 0; i < w; i++)
			{
				cout << symbol;
			}
		}
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
		return x > 0 && y > 0 && x < 40 && y < 15;
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



	time_t interval = 500;
	time_t start = clock();

	while (true)
	{
		if (clock() >= start + 500)
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