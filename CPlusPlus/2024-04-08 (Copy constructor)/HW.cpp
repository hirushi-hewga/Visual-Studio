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
	Train(const Train& other)
	{
		model = other.model;
		countCarriages = other.countCarriages;
		carriages = new Carriage[other.countCarriages];
		for (int i = 0; i < other.countCarriages; i++)
		{
			carriages[i].number = other.carriages[i].number;
			carriages[i].places = other.carriages[i].places;
			carriages[i].passangers = other.carriages[i].passangers;
		}
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
	string GetModel()
	{
		return model;
	}
	void AddPassanger()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > countCarriages)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
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







void CopyTrain(Train*& trains, int& count)
{
	if (count == 0) cout << "Trains not found!" << endl;
	else
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > count)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << " - Train [ " << trains[i].GetModel() << " ]" << endl;
			}
			cout << "Choice train to copy : ";
			cin >> choice;
		}
		Train* temp = new Train[count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = trains[i];
		}
		temp[count] = Train(trains[choice - 1]);
		if (trains != nullptr)
			delete[] trains;
		trains = temp;
		count++;
		cout << endl;
	}
}

void AddTrain(Train*& trains, int& count)
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 2)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		cout << "1 - Add default train" << endl;
		cout << "2 - Add train with name" << endl;
		cout << "Enter your choice : " << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		Train* temp = new Train[count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = trains[i];
		}
		temp[count] = Train();
		if (trains != nullptr)
			delete[] trains;
		trains = temp;
		count++;
	}
	if (choice == 2)
	{
		Train* temp = new Train[count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = trains[i];
		}
		string model;
		cout << "Enter train name : ";
		cin >> model;
		temp[count] = Train(model);
		if (trains != nullptr)
			delete[] trains;
		trains = temp;
		count++;
	}
}

void AddPassanger(Train*& trains, int count)
{
	if (count == 0) cout << "Trains not found!" << endl;
	else
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > count)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << " - Train [ " << trains[i].GetModel() << " ]" << endl;
			}
			cout << "Enter your choice : ";
			cin >> choice;
		}
		trains[choice - 1].AddPassanger();
		cout << endl;
	}
}

void AddCarriage(Train*& trains, int count)
{
	if (count == 0) cout << "Trains not found!" << endl;
	else
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > count)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << " - Train [ " << trains[i].GetModel() << " ]" << endl;
			}
			cout << "Enter your choice : ";
			cin >> choice;
		}
		trains[choice - 1].AddCarriage();
		cout << endl;
	}
}

void ShowTrain(Train*& trains, int count)
{
	if (count == 0) cout << "Trains not found!" << endl;
	else
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > count)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << " - Train [ " << trains[i].GetModel() << " ]" << endl;
			}
			cout << "Enter your choice : ";
			cin >> choice;
		}
		trains[choice - 1].Show();
		cout << endl;
	}
}

void AddPassanger(Train& train)
{
	if (train.GetCountCarriages() != 0) train.AddPassanger();
	else cout << "No carriages found!" << endl;
}

int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 5)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		cout << endl;
		isValidData = false;
		cout << "1 - Show train" << endl;
		cout << "2 - Add train" << endl;
		cout << "3 - Copy train" << endl;
		cout << "4 - Add carriage" << endl;
		cout << "5 - Add passanger" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}

enum MENU { SHOW = 1, ADD_TRAIN, COPY_TRAIN, ADD_CARRIAGE, ADD_PASSANGER, EXIT };

int main()
{
	int countTrains = 0;
	Train* trains = nullptr;
	bool isExit = false;
	while (!isExit)
	{
		cout << endl;
		cout << "------------------------" << endl;
		switch (Menu())
		{
		case MENU::SHOW: ShowTrain(trains, countTrains); break;
		case MENU::ADD_TRAIN: AddTrain(trains, countTrains); break;
		case MENU::COPY_TRAIN: CopyTrain(trains, countTrains); break;
		case MENU::ADD_CARRIAGE: AddCarriage(trains, countTrains); break;
		case MENU::ADD_PASSANGER: AddPassanger(trains, countTrains); break;
		case MENU::EXIT: isExit = true;
		}
		cout << "------------------------" << endl;
	}
	cout << "Good bye." << endl;
	delete[] trains;
}