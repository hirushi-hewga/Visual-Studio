#include <iostream>
#include <conio.h>
#include "Header.h"
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
	char a[5];
	char b[5];
	char c[5];
};

struct MotorCar
{
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
	delete[] cars;
}



void ShowAllCars(MotorCar* cars, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Color: " << cars[i].color << ", Model: " << cars[i].model << endl;
	}
}

MotorCar* CopyStructures(MotorCar* c, int& size)
{
	MotorCar* temp = new MotorCar[size];
	MotorCar cars[10] = { { "orange","Skoda",{"BK","1111","IT"} },
							{ "green","Mazda",{"BK","1112","IT"} },
							{ "blue","Toyota",{"BK","1113","IT"} },
							{ "red","Honda",{"BK","1114","IT"} },
							{ "yellow","Ford",{"BK","1115","IT"} },
							{ "black","Chevrolet",{"BK","1116","IT"} },
							{ "white","Nissan",{"BK","1117","IT"} },
							{ "silver","Hyundai",{"BK","1118","IT"} },
							{ "gray","Kia",{"BK","1119","IT"} },
							{ "purple","Volkswagen",{"BK","1120","IT"} } };
	for (int i = 0; i < 10; i++)
	{
		*(temp + i) = cars[i];
	}
	delete[] c;
	c = new MotorCar[10];
	for (int i = 0; i < 10; i++)
	{
		*(c + i) = *(temp + i);
	}
	delete[] temp;
	size = 10;
	return c;
}