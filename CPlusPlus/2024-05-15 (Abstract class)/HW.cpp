#include <iostream>
using namespace std;



class Animal
{
	string name;
	float weight;
	string place;
	int age;
public:
	Animal() :name("no name"), weight(0), place("no place"), age(0) {}
	Animal(string name, float weight, string place, int age) :name(name), place(place)
	{
		this->weight = weight > 0 ? weight : 0;
		this->age = age > 0 ? age : 0;
	}
	Animal(const Animal& other)
	{
		this->name = other.name;
		this->weight = other.weight;
		this->place = other.place;
		this->age = other.age;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Weight : " << weight << endl;
		cout << "Place : " << place << endl;
		cout << "Age : " << age << endl;
	}
};



class Fox : public Animal
{
public:
	Fox() : Animal() {}
	Fox(string name, float weight, string place, int age) : Animal(name, weight, place, age) {}
	Fox(const Fox& other) : Animal(other) {}
};



class Rabbit : public Animal
{
public:
	Rabbit() :Animal() {}
	Rabbit(string name, float weight, string place, int age) :Animal(name, weight, place, age) {}
	Rabbit(const Rabbit& other) : Animal(other) {}
};





class Plant
{
	string place;
public:
	Plant() : place("no place") {}
	Plant(string place) : place(place) {}
	Plant(const Plant& other)
	{
		this->place = other.place;
	}
	void ShowInfo()const
	{
		cout << "Place : " << place << endl;
	}
};



class Grass : public Plant
{
public:
	Grass() :Plant() {}
	Grass(string place) :Plant(place) {}
	Grass(const Grass& other) : Plant(other) {}
};





class Live
{
	Fox* fox;
	int foxCount;
	Rabbit* rabbit;
	int rabbitCount;
	Grass* grass;
	int grassCount;
public:
	Live() :fox(nullptr), rabbit(nullptr), grass(nullptr) {}


	void DeleteGrass()
	{
		delete[] grass;
		grass = nullptr;
		grassCount = 0;
	}
	void AddFox()
	{
		if (foxCount < 5)
		{
			Fox* temp = new Fox[foxCount + 1];
			for (int i = 0; i < foxCount; i++)
			{
				temp[i] = Fox(fox[i]);
			}
			temp[foxCount++] = Fox();
			delete[] fox;
			fox = temp;
		}
	}
	void AddRabbit()
	{
		if (rabbitCount < 5)
		{
			Rabbit* temp = new Rabbit[rabbitCount + 1];
			for (int i = 0; i < rabbitCount; i++)
			{
				temp[i] = Rabbit(rabbit[i]);
			}
			temp[rabbitCount++] = Rabbit();
			delete[] rabbit;
			rabbit = temp;
		}
		if (grassCount <= rabbitCount && grassCount != 0)
			DeleteGrass();
	}
	void AddGrass()
	{
		if (grassCount < 5)
		{
			Grass* temp = new Grass[grassCount + 1];
			for (int i = 0; i < grassCount; i++)
			{
				temp[i] = Grass(grass[i]);
			}
			temp[grassCount++] = Grass();
			delete[] grass;
			grass = temp;
		}
		if (grassCount <= rabbitCount)
			DeleteGrass();
	}
	void Show()const
	{
		cout << "======== Fox [ " << foxCount << " ] ========" << endl;
		for (int i = 0; i < foxCount; i++)
		{
			cout << "---- fox " << i + 1 << " ----" << endl;
			fox[i].ShowInfo();
		}
		cout << "======== Rabbit [ " << rabbitCount << " ] ========" << endl;
		for (int i = 0; i < rabbitCount; i++)
		{
			cout << "---- rabbit " << i + 1 << " ----" << endl;
			rabbit[i].ShowInfo();
		}
		cout << "======== Grass [ " << grassCount << " ] ========" << endl;
		for (int i = 0; i < grassCount; i++)
		{
			cout << "---- grass " << i + 1 << " ----" << endl;
			grass[i].ShowInfo();
		}
		cout << endl << endl << endl;
	}


	~Live()
	{
		if (fox != nullptr) delete[] fox;
		if (rabbit != nullptr) delete[] rabbit;
		if (grass != nullptr) delete[] grass;
	}
};



int main()
{
	Live live;
	live.Show();
	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();


	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();


	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();


	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();


	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();


	live.AddFox();
	live.AddRabbit();
	live.AddGrass();
	live.Show();
}