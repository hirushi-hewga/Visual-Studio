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
public:
	virtual void PrepareSouce()const = 0;
};

class MilanSouce : public Souce
{
public:
	void PrepareSouce()const override
	{
		cout << "I prepare Milan souce" << endl;
	}
};
class GreeceSouce : public Souce
{
public:
	void PrepareSouce()const override
	{
		cout << "I prepare Greece souce" << endl;
	}
};



class Fabric
{
public:
	virtual void PreparePizza()const = 0;
	virtual void PrepareSouce()const = 0;
};

class FabricMilan : public Fabric
{
public:
	void PreparePizza()const override
	{
		cout << "I prepare pizza" << endl;
	}
	void PrepareSouce()const override
	{
		cout << "I prepare souce" << endl;
	}
};

class FabricGreece : public Fabric
{
public:
	void PreparePizza()const override
	{
		cout << "I prepare pizza" << endl;
	}
	void PrepareSouce()const override
	{
		cout << "I prepare souce" << endl;
	}
};



int main()
{

}