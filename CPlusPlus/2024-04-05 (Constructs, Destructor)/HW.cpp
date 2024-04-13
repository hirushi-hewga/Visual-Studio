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
		cout << "--Construct rectangle--" << endl;
		height = 0;
		width = 0;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int size)
	{
		cout << "--Construct rectangle--" << endl;
		height = size;
		width = size;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int height, int width)
	{
		cout << "--Construct rectangle--" << endl;
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
		else cout << "Error size data. Data has not changed" << endl;
	}
	void SetCoord(int x, int y)
	{
		if (x >= 0 && y >= 0)
		{
			coord.x = x;
			coord.y = y;
		}
		else cout << "Error coord data. Data has not changed" << endl;
	}
	~Rectangle()
	{
		cout << "--Destruct rectangle--" << endl;
	}
};



enum MENU { CREATE = 1, SHOW, SETSIZE, SETCOORD };

int main()
{





	//getch
}