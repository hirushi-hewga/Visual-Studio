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
	virtual Pizza* PreparePizza()const = 0;
	virtual Souce* PrepareSouce()const = 0;
};

class FabricMilan : public Fabric
{
public:
	Pizza* PreparePizza()const override
	{
		return new MilanPizza();
	}
	Souce* PrepareSouce()const override
	{
		return new MilanSouce();
	}
};

class FabricGreece : public Fabric
{
public:
	Pizza* PreparePizza()const override
	{
		cout << "I prepare Greece pizza" << endl;
	}
	Souce* PrepareSouce()const override
	{
		cout << "I prepare Greece souce" << endl;
	}
};



int main()
{

	FabricMilan milan;
	Pizza* pizza = milan.PreparePizza();
	Souce* souce = milan.PrepareSouce();

	pizza->PreparePizza();
	souce->PrepareSouce();

	delete pizza;
	delete souce;

}