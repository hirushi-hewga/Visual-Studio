#include <iostream>
using namespace std;

struct Coord
{
	int x;
	int y;
};

class Rectangle
{
	int height;
	int width;
	char symbol;
	Coord coord;
public:
	Rectangle()
	{
		height = 0;
		width = 0;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int size)
	{
		height = size;
		width = size;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int height, int width)
	{
		this->height = height;
		this->width = width;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	void Show()
	{
		for (int i = 0; i < coord.y + width; i++) cout << '=';
		cout << endl;

		for (int i = 0; i < coord.y; i++) cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int i = 0; i < coord.x; i++) cout << ' ';
			for (int i = 0; i < width; i++) cout << symbol;
			cout << endl;
		}

		for (int i = 0; i < coord.y + width; i++) cout << '=';
		cout << endl;
	}
	void SetSize(int height, int width)
	{
		if (height > 0 && width > 0)
		{
			this->height = height;
			this->width = width;
		}
		else cout << "Error size data." << endl;
	}
};



int main()
{






	//getch
}