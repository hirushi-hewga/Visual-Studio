



class Hero
{
	string name;
	int hp;
	int h, w;
	COORD position;
	char symbol;

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
	Hero() : name("no name"), hp(100), h(1), w(1), position({0, 0}), symbol('#') {}
	Hero(string name, int h, int w, char s) : name(name), hp(100), position({0, 0}), symbol(s)
	{
		this->h = h >= 1 ? h : 1;
		this->w = w >= 1 ? w : 1;
	}
	void PrintHero()const
	{
		Print(symbol);
	}
	void ClearHero()const
	{
		Print(' ');
	}
	void ShowInfo()const
	{
		cout << "---------------- Player [ " << name << " ] | HP : " << hp << " ----------------" << endl;
	}
	void Move(int x, int y)
	{
		position.Y = y >= 0 ? y : 0;
		position.X = x >= 0 ? x : 0;
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
	while (true)
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