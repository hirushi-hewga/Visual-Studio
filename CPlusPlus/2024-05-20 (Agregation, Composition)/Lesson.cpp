#include <iostream>
using namespace std;

class Carteidge
{
public:
	enum TYPE { NONE, STANDART, L, XL };
private:
	string color;
	float volume;
	TYPE type;
public:
	Carteidge() : color("no color"), volume(0), type(NONE) {}
	Carteidge(string c, float v, TYPE t) : color(c), volume(v), type(t) {}

	void Show()
	{
		cout << "Color : " << color << endl;
		cout << "Volume : " << volume << endl;
	}
};

class Printer
{

};



int main()
{

}