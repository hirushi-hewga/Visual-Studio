#include <iostream>
using namespace std;

class Array
{
	int size;
	long* arr;
public:
	Array():size(0), arr(nullptr){}
	explicit Array(int size)
	{
		this->size = size;
		arr = new long[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const Array& other)
	{
		size = other.size;
		arr = nullptr;
		if (size != 0)
		{
			arr = new long[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = other.arr[i];
			}
		}
	}

	~Array()
	{
		delete[] arr;
	}
};

class ArrayList
{
	int count;
	Array* array;
public:
	ArrayList():count(0), array(nullptr){}

	~ArrayList()
	{
		delete[] array;
	}
};




int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 8)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		isValidData = false;
		cout << endl;
		cout << "1 - Add array" << endl;
		cout << "2 - Init array" << endl;
		cout << "3 - Show array" << endl;
		cout << "4 - Add element to array" << endl;
		cout << "5 - Remove array element" << endl;
		cout << "6 - Sort array" << endl;
		cout << "7 - Get min max element, average value from array" << endl;
		cout << "8 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { ADD = 1, INIT, SHOW, ADD_ELEM, RM_ELEM, SORT, GET_VALUES, EXIT };
int main()
{
	srand(time(NULL));
	ArrayList array_list;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::ADD:  break;
		case MENU::INIT:  break;
		case MENU::SHOW:  break;
		case MENU::ADD_ELEM:  break;
		case MENU::RM_ELEM:  break;
		case MENU::SORT:  break;
		case MENU::GET_VALUES:  break;
		case MENU::EXIT: isExit = true;
		}
	}
	cout << "Good bye." << endl;
}