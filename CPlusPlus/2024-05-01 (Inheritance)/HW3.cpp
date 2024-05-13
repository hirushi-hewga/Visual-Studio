#include <iostream>
using namespace std;

class Animal
{
protected:
	string species;
	int speed;
	float weight;
	string living;
public:
	Animal() = delete;
	Animal(string species, int speed, int weight, string living):species(species), speed(speed), weight(weight), living(living) {}


	void Move()
	{

	}
	void Print()const
	{
		cout << "Species : " << species << endl;
		cout << "Speed : " << speed << " km/h" << endl;
		cout << "Weight : " << weight << " kg" << endl;
		cout << "Living environment : " << living << endl;
	}
	void Say()
	{

	}
};



int main()
{

}