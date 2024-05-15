#include <iostream>
using namespace std;



class Animal
{
	string name;
	float weight;
	string place;
public:
	Animal():name("no name"), weight(0), place("no place") {}
	Animal(string name, float weight, string place):name(name), place(place)
	{
		this->weight = weight > 0 ? weight : 0;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Weight : " << weight << endl;
		cout << "Place : " << place << endl;
	}
};



class Fox : public Animal
{
	static int count;
public:
	Fox() :Animal()	{ count++; }
	Fox(string name, float weight, string place) : Animal(name, weight, place) { count++; }
};



class Rabbit : public Animal
{
	static int count;
public:
	Rabbit() :Animal() { count++; }
	Rabbit(string name, float weight, string place) :Animal(name, weight, place) { count++; }
};





class Plant
{
	string name;
	float height;
	string place;
public:
	Plant() :name("no name"), height(0), place("no place") {}
	Plant(string name, float height, string place) :name(name), place(place)
	{
		this->height = height > 0 ? height : 0;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Height : " << height << endl;
		cout << "Place : " << place << endl;
	}
};



class Grass : public Plant
{
	static int count;
public:
	Grass() :Plant() { count++; }
	Grass(string name, float height, string place) :Plant(name, height, place) { count++; }
};





class Live
{
	Fox* fox;
	Rabbit* rabbit;
	Grass* grass;
public:
	Live():fox(nullptr), rabbit(nullptr), grass(nullptr) {}


	void AddFox()
	{

	}
	void AddRabbit()
	{

	}
	void AddGrass()
	{

	}


	~Live()
	{
		if (fox != nullptr) delete[] fox;
		if (rabbit != nullptr) delete[] rabbit;
		if (grass != nullptr) delete[] grass;
	}
};





int Fox::count = 0;
int Rabbit::count = 0;
int Grass::count = 0;
int main()
{

}