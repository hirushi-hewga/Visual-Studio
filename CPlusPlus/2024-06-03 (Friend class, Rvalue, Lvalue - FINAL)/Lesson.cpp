#include <iostream>
using namespace std;

class Rectangle;
class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int x, int y) : x{x}, y{y} { this->x = x; }
	int GetX()const { return x; }
	int GetY()const { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void Show()const
	{
		cout << "Point - X:" << x << " Y:" << y << endl;
	}
};





int main()
{

}