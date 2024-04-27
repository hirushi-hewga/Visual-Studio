#include <iostream>
using namespace std;

class Airplane
{
	string model;
	string type;
	int maxPassangersCount;
	int passangersCount;


#pragma region operators

#pragma endregion
	friend bool operator ==(const Airplane& left, const Airplane& right);
};



bool operator ==(const Airplane& left, const Airplane& right)
{

}



int main()
{

}