#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
	string name;
public:
	Shape():name("no name") {}
	Shape(string n):name(n) {}

	virtual void Show()const
	{
		cout << "Name : " << name << endl;
	}
	virtual void GetArea()const = 0 {};
};

class Rectangle : public Shape
{
	float side_1;
	float side_2;
public:
	Rectangle():side_1(0), side_2(0), Shape() {}
	Rectangle(string n, float s1, float s2):side_1(s1),side_2(s2),Shape(n) {}

	void Show()const override
	{
		cout << "======== Rectangle ========" << endl;
		Shape::Show();
		cout << "Side 1 : " << side_1 << " sm" << endl;
		cout << "Side 2 : " << side_2 << " sm" << endl;
	}
	void GetArea()const override
	{
		return side_1 * side_2;
	}
};

class Circle : public Shape
{
	float radius;
public:
	Circle() :radius(0), Shape() {}
	Circle(string n, float r) :radius(r), Shape(n) {}

	void Show()const override
	{
		cout << "======== Circle ========" << endl;
		Shape::Show();
		cout << "Radius : " << radius << " sm" << endl;
	}
	void GetArea()const override
	{
		return pow(3.14 * radius, 2);
	}
};

class RightTriangle : public Shape
{
	float katet_1;
	float katet_2;
public:
	RightTriangle() :katet_1(0), katet_2(0), Shape() {}
	RightTriangle(string n, float k1, float k2) :katet_1(k1), katet_2(k2), Shape(n) {}

	void Show()const override
	{
		cout << "======== Right Triangle ========" << endl;
		Shape::Show();
		cout << "Katet 1 : " << katet_1 << " sm" << endl;
		cout << "Katet 2 : " << katet_2 << " sm" << endl;
	}
	void GetArea()const override
	{
		return (katet_1 * katet_2) / 2;
	}
};

class Triangle : public Shape
{
	float side_1;
	float side_2;
	float side_3;
public:
	Triangle() :side_1(0), side_2(0), side_3(0), Shape() {}
	Triangle(string n, float s1, float s2, float s3) :side_1(s1), side_2(s2), side_3(s3), Shape(n) {}

	void Show()const override
	{
		cout << "======== Triangle ========" << endl;
		Shape::Show();
		cout << "Side 1 : " << side_1 << " sm" << endl;
		cout << "Side 2 : " << side_2 << " sm" << endl;
		cout << "Side 3 : " << side_3 << " sm" << endl;
	}
	void GetArea()const override
	{
		double p = (side_1 + side_2 + side_3) / 2;
		return sqrt(p * (p - side_1) * (p - side_2) * (p - side_3));
	}
};



int main()
{

}