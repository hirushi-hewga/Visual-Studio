#include <iostream>
using namespace std;


struct Carriage
{
	int number;
	int places;
	int passangers;
	void Show()
	{
		cout << "Number : " << number << endl;
		cout << "Places : " << places << endl;
		cout << "Passangers : " << passangers << endl;
	}
};
class Train
{
private:
	string model;
	int countCarriages;
	Carriage* carriages;
public:
	Train()
	{
		model = "noModel";
		countCarriages = 0;
		carriages = nullptr;
	}
	Train(string model)
	{
		this->model = model;
		countCarriages = 0;
		carriages = nullptr;
	}
	void Show()
	{
		cout << "Model : " << model << ", carriage count : " << countCarriages;
		for (int i = 0; i < countCarriages; i++)
		{
			carriages[i].Show();
			cout << endl;
		}
	}
	void AddCarriage()
	{
		countCarriages++;
	}
};



int main()
{
	Train train("Tom");
	train.Show();
	train.AddCarriage();
	train.Show();
}