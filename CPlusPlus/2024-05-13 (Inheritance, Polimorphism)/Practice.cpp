#include <iostream>
using namespace std;

class Employer
{
protected:
	int death_count;
public:
	Employer():death_count(0) {}


	virtual void Print()const
	{
		cout << "======== Employer ========" << endl;
		cout << "Death count : " << death_count << endl;
	}
};

class President : public Employer
{

};

class Manager : public Employer
{

};

class Worker : public Employer
{

};



int main()
{

}