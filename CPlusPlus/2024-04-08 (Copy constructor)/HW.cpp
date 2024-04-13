#include <iostream>
using namespace std;

struct Carriage
{
	int number;
	int places;
	int passangers;
	void Show()
	{
		cout << "======== Carriage [" << number << "] ========" << endl;
		cout << "Places : " << places << endl;
		cout << "Passangers : " << passangers << endl;
	}
};

class Train
{
	string model;
	int countCarriages;
	Carriage* carriages;
public:
	Train()
	{
		cout << "-- Construct --" << endl;
		model = "No model";
		countCarriages = 0;
		carriages = nullptr;
	}
	Train(string model)
	{
		cout << "-- Construct --" << endl;
		this->model = model;
		countCarriages = 0;
		carriages = nullptr;
	}
	void InitCarriage(Carriage& carriage)
	{
		carriage.number = countCarriages + 1;
		carriage.places = 20;
		carriage.passangers = 0;
	}
	void Show()
	{
		cout << endl;
		cout << "Train : " << model << endl;
		for (int i = 0; i < countCarriages; i++)
		{
			carriages[i].Show();
			cout << endl;
		}
	}
	void AddCarriage()
	{
		Carriage* temp = new Carriage[countCarriages + 1];
		for (int i = 0; i < countCarriages; i++)
		{
			temp[i] = carriages[i];
		}
		InitCarriage(temp[countCarriages]);
		if (carriages != nullptr)
			delete[] carriages;
		carriages = temp;
		countCarriages++;
	}
	int GetCountCarriages()
	{
		return countCarriages;
	}
	void AddPassanger()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > countCarriages)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			cout << "Enter carriage number ( 1 - " << countCarriages << " ) : ";
			cin >> choice;
		}
		if (carriages[choice].passangers == carriages[choice].places) cout << "Carriage [ " << choice << " ] is full" << endl;
		else carriages[choice - 1].passangers++;
	}
	~Train()
	{
		cout << "-- Destruct " << model << " --" << endl;
		delete[] carriages;
	}
};



void AddPassanger(Train& train)
{
	if (train.GetCountCarriages() != 0) train.AddPassanger();
	else cout << "No carriages found!" << endl;
}

int Menu()
{
	int choice = 0;
	while (choice < 1 || choice > 4)
	{
		cout << "1 - Show train" << endl;
		cout << "2 - Add carriage" << endl;
		cout << "3 - Add passanger" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}

enum MENU { SHOW = 1, ADD_CARRIAGE, ADD_PASSANGER, EXIT };

int main()
{
	Train train("Tom");
	bool isExit = false;
	while (!isExit)
	{
		cout << endl;
		cout << "------------------------" << endl;
		switch (Menu())
		{
		case MENU::SHOW: train.Show(); break;
		case MENU::ADD_CARRIAGE: train.AddCarriage(); break;
		case MENU::ADD_PASSANGER: AddPassanger(train); break;
		case MENU::EXIT: isExit = true;
		}
		cout << "------------------------" << endl;
	}
	cout << "Good bye." << endl;
}