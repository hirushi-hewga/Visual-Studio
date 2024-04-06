#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cctype>
using namespace std;

struct WashMashine
{
	char company[20];
	char color[20];
	float width;
	float length;
	float height;
	float power;
	float spinSpeed;
	float heatingTemperature;
};

struct Praska
{
	char brand[20];
	char model[20];
	char color[20];
	int minTemperature;
	int maxTemperature;
	char steamDelivery;
	int power;
};

struct Boiler
{
	char company[20];
	char color[20];
	int power;
	int capacity;
	int heatingTemperature;
};

struct CarNumber
{
	char a[3];
	char b[5];
	char c[3];
};

struct MotorCar
{
	int id;
	char color[20];
	char model[20];
	CarNumber number;
};



WashMashine CreateWashMashine()
{
	WashMashine temp;
	cout << "Enter washing mashine company: ";
	cin >> temp.company;
	cout << "Enter washing mashine color: ";
	cin >> temp.color;
	cout << "Enter washing mashine width: ";
	cin >> temp.width;
	cout << "Enter washing mashine length: ";
	cin >> temp.length;
	cout << "Enter washing mashine height: ";
	cin >> temp.height;
	cout << "Enter washing mashine power: ";
	cin >> temp.power;
	cout << "Enter washing mashine spin speed: ";
	cin >> temp.spinSpeed;
	cout << "Enter washing mashine heating temperature: ";
	cin >> temp.heatingTemperature;
	return temp;
}

Praska CreatePraska()
{
	Praska temp;
	cout << "Enter praska brand: ";
	cin >> temp.brand;
	cout << "Enter praska model: ";
	cin >> temp.model;
	cout << "Enter praska color: ";
	cin >> temp.color;
	cout << "Enter praska minimum temperature: ";
	cin >> temp.minTemperature;
	cout << "Enter praska maximum temperature: ";
	cin >> temp.maxTemperature;
	cout << "Enter praska steam delivery y/n: ";
	temp.steamDelivery = _getch();
	cout << endl;
	cout << "Enter praska power: ";
	cin >> temp.power;
	return temp;
}

Boiler CreateBoiler()
{
	Boiler temp;
	cout << "Enter boiler company: ";
	cin >> temp.company;
	cout << "Enter boiler color: ";
	cin >> temp.color;
	cout << "Enter boiler power: ";
	cin >> temp.power;
	cout << "Enter boiler capacity: ";
	cin >> temp.capacity;
	cout << "Enter boiler heating temperature: ";
	cin >> temp.heatingTemperature;
	return temp;
}



void ShowWashMashine(WashMashine m)
{
	cout << "============== WashingMashine ==============" << endl;
	cout << "Company: " << m.company << endl;
	cout << "Color: " << m.color << endl;
	cout << "Width: " << m.width << endl;
	cout << "Length: " << m.length << endl;
	cout << "Height: " << m.height << endl;
	cout << "Power: " << m.power << endl;
	cout << "Spin speed: " << m.spinSpeed << endl;
	cout << "Heating temperature: " << m.heatingTemperature << endl;
}

void ShowPraska(Praska p)
{
	cout << "================== Praska ==================" << endl;
	cout << "Brand: " << p.brand << endl;
	cout << "Model: " << p.model << endl;
	cout << "Color: " << p.color << endl;
	cout << "Minimum temperature: " << p.minTemperature << endl;
	cout << "Maximum temperature: " << p.maxTemperature << endl;
	cout << "Steam delivery y/n: " << p.steamDelivery << endl;
	cout << "Power: " << p.power << endl;
}

void ShowBoiler(Boiler b)
{
	cout << "================== Boiler ==================" << endl;
	cout << "Company: " << b.company << endl;
	cout << "Color: " << b.color << endl;
	cout << "Power: " << b.power << endl;
	cout << "Capacity: " << b.capacity << endl;
	cout << "Heating temperature: " << b.heatingTemperature << endl;
}

MotorCar* CopyStructures(MotorCar* c, int& size);
void ShowAllCars(MotorCar* cars, int size);
void ShowCarById(MotorCar* c, int size);
void ShowCarsId(MotorCar* c, int size);
void SearchCarByNumber(MotorCar* c, int size);
void ShowCarsNumber(MotorCar* c, int size);
MotorCar* EditCar(MotorCar* c, int size);
MotorCar InitCar(MotorCar* c, MotorCar car, int index, int size);

int main()
{
	/*
	WashMashine washingMashine = CreateWashMashine();
	ShowWashMashine(washingMashine);
	*/




	/*
	Praska praska = CreatePraska();
	ShowPraska(praska);
	*/




	/*
	Boiler boiler = CreateBoiler();
	ShowBoiler(boiler);
	*/




	/**/
	int size = 10;
	MotorCar* cars = new MotorCar[size];
	cars = CopyStructures(cars, size);

	ShowAllCars(cars, size);

	ShowCarById(cars, size);

	SearchCarByNumber(cars, size);

	cars = EditCar(cars, size);

	ShowAllCars(cars, size);

	delete[] cars;
}



MotorCar InitCar(MotorCar* c, MotorCar car, int index, int size)
{
	bool BOOL = true;
	int* id = new int[size - 1];
	cout << "Enter id : ";
	cin >> car.id;
	for (int i = 0; i < index; i++) *(id + i) = (*(c + i)).id;
	for (int i = index + 1; i < size; i++) *(id + i - 1) = (*(c + i)).id;
	do
	{
		if (!BOOL)
		{
			cout << "Id exist. Try again!" << endl;
			cout << "Enter id : ";
			cin >> car.id;
		}
		BOOL = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (car.id == *(id + i))
			{
				BOOL = false;
				break;
			}
		}
	} while (!BOOL);
	delete[] id;
	
	cout << "Enter car color : ";
	cin >> car.color;
	
	cout << "Enter car model : ";
	cin >> car.model;

	BOOL = true;
	string region;
	do{
		if (!BOOL)
		{
			cout << "Error region. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter car region (BK) : ";
		cin >> region;
		if (isupper(region[0]) && isalpha(region[0]) && isupper(region[1]) && isalpha(region[1]))
		{
			BOOL = true;
		}
	} while (BOOL);
	car.number.a[0] = region[0];
	car.number.a[1] = region[1];

	BOOL = true;
	int number;
	do {
		if (!BOOL)
		{
			cout << "Error number. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter car number (1234) : ";
		cin >> number;
		if (isdigit(number % 10) && isdigit(number % 100 / 10) && isdigit(number % 1000 / 100) && isdigit(number / 1000))
		{
			BOOL = true;
		}
	} while (BOOL);
	car.number.b[0] = 1;
	car.number.b[1] = 2;
	car.number.b[2] = 3;
	car.number.b[3] = 4;

	cout << "Enter car series (IT) : ";
	cin >> car.number.c;

	string series;
	do {
		BOOL = true;
		if (!BOOL)
		{
			cout << "Error series. Try again!" << endl;
		}
		cout << "Enter car series (IT) : " << endl;
		cin >> series;
		for (int i = 65; i <= 90; i++)
		{
			if ((char)i == series[0])
			{
				BOOL = false;
				break;
			}
		}
		if (!BOOL)
		{
			BOOL = true;
			for (int i = 65; i <= 90; i++)
			{
				if ((char)i == series[1])
				{
					BOOL = false;
					break;
				}
			}
		}
	} while (!BOOL);
	car.number.c[0] = series[0];
	car.number.c[1] = series[1];

	return car;
}

MotorCar* EditCar(MotorCar* c, int size)
{
	ShowCarsNumber(c, size);
	int Index;
	cout << "Choice car number (1 - " << size << ") : ";
	cin >> Index;
	while (Index<1 || Index>size)
	{
		cout << "Try again : ";
		cin >> Index;
	}
	Index--;
	MotorCar* temp = new MotorCar[size];
	for (int i = 0; i < Index; i++)
	{
		*(temp + i) = *(c + i);
	}
	InitCar(c, *(temp + Index), Index, size);
	for (int i = Index + 1; i < size; i++)
	{
		*(temp + i) = *(c + i);
	}
	delete[] c;
	c = temp;
	return c;
}

void ShowCarsNumber(MotorCar* c, int size)
{
	cout << "======= Number =======" << endl;
	for (int i = 0; i < size; i++) cout << i + 1 << " - " << c[i].number.a << c[i].number.b << c[i].number.c << endl;
}

void SearchCarByNumber(MotorCar* c, int size)
{
	ShowCarsNumber(c, size);
	int choice;
	cout << "Choice car number (1 - " << size << ") : ";
	cin >> choice;
	while (choice<1 || choice>size)
	{
		cout << "Try again : ";
		cin >> choice;
	}
	cout << "----------------------" << endl;
	cout << "Id : " << c[choice - 1].id << endl;
	cout << "Color : " << c[choice - 1].color << endl;
	cout << "Model : " << c[choice - 1].model << endl;
	cout << "Number : " << c[choice - 1].number.a << c[choice - 1].number.b << c[choice - 1].number.c << endl;
	cout << "----------------------" << endl;
}

void ShowCarsId(MotorCar* c, int size)
{
	cout << "========= Id =========" << endl;
	for (int i = 0; i < size; i++) cout << "Id : " << c[i].id << ", Model : " << c[i].model << endl;
}

void ShowCarById(MotorCar* c, int size)
{
	bool BOOL = false;
	ShowCarsId(c, size);
	int choice;
	cout << "Enter id : ";
	cin >> choice;
	int* id = new int[size];
	for (int i = 0; i < size; i++) *(id + i) = (*(c + i)).id;
	int carIndex;
	do
	{
		if (BOOL)
		{
			cout << "Try again : ";
			cin >> choice;
		}
		BOOL = true;
		for (int i = 0; i < size; i++) if (choice == c[i].id)
		{
			BOOL = false;
			carIndex = i;
			break;
		}
	} while (BOOL);
	delete[] id;
	cout << "----------------------" << endl;
	cout << "Id : " << c[carIndex].id << endl;
	cout << "Color : " << c[carIndex].color << endl;
	cout << "Model : " << c[carIndex].model << endl;
	cout << "Number : " << c[carIndex].number.a << c[carIndex].number.b << c[carIndex].number.c << endl;
	cout << "----------------------" << endl;
}

void ShowAllCars(MotorCar* c, int size)
{
	cout << "======== Cars ========" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Id : " << c[i].id << endl;
		cout << "Color : " << c[i].color << endl;
		cout << "Model : " << c[i].model << endl;
		cout << "Number : " << c[i].number.a << c[i].number.b << c[i].number.c << endl;
		cout << "----------------------" << endl;
	}
}

MotorCar* CopyStructures(MotorCar* c, int& size)
{
	MotorCar* temp = new MotorCar[size]{
		{ 1, "orange","Skoda",{"BK","1111","IT"} },
		{ 2, "green","Mazda",{"BK","1112","IT"} },
		{ 3, "blue","Toyota",{"BK","1113","IT"} },
		{ 4, "red","Honda",{"BK","1114","IT"} },
		{ 5, "yellow","Ford",{"BK","1115","IT"} },
		{ 6, "black","Chevrolet",{"BK","1116","IT"} },
		{ 7, "white","Nissan",{"BK","1117","IT"} },
		{ 8, "silver","Hyundai",{"BK","1118","IT"} },
		{ 9, "gray","Kia",{"BK","1119","IT"} },
		{ 10, "purple","Volkswagen",{"BK","1120","IT"}
	} };
	return temp;
}