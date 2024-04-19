/*
#include <iostream>
using namespace std;

class Rectangle
{
	int w;
	int h;
public:
	Rectangle():w(2),h(2){}
	Rectangle(int value):w(value),h(value){}
	Rectangle(int w, int h):w(w),h(h){}
	void Show()
	{
		cout << "Width : " << w << " ,  Height : " << h << endl;
	}
	//void operator [type] (argument){}
	//operator typename(){}//1
	//operator typename()const{}//2
	//explicit operator typename()const{}//3
	operator int()
	{
		return w * h;
	}
	operator Square();
};



class Square
{
	int side;
public:
	Square():side(2){}
	Square(int side):side(side){}
	void Show()const
	{
		cout << "Width : " << side << " ,  Height : " << side << endl;
	}
	operator Rectangle()
	{
		Rectangle newR(side, side + 50);
		return newR;
	}
};

Rectangle::operator Square()
{
	return Square(w + h);
}




int main()
{
	int value = 9;
	double valueD = value; // int ==> double


	Rectangle rectangle(5, 10); // standart to abstract
	Square square(7); // standart to abstract
	rectangle.Show();
	square.Show();


	// explicit
	value = (int)rectangle;   // abstract to standart
	cout << "Value : " << value << endl;


	rectangle = square;
	rectangle.Show();


	square = rectangle;
	square.Show();
}
*/