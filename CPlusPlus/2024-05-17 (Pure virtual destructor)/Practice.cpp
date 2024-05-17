#include <iostream>
using namespace std;

class Pizza
{
public:
	virtual void PreparePizza()const = 0;
};

class MilanPizza : public Pizza
{
public:
	void PreparePizza()const override
	{
		cout << "I prepare Milan pizza" << endl;
	}
};

class GreecePizza : public Pizza
{
public:
	void PreparePizza()const override
	{
		cout << "I prepare Greece pizza" << endl;
	}
};



class Souce
{

};



int main()
{

}