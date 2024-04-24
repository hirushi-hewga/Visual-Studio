#include <iostream>
using namespace std;

class Array
{
	int size;
	long* arr;
public:
	Array():size(0),arr(nullptr){}
	Array(int size):size(size)
	{
		arr = nullptr;
		if (size != 0) {
			arr = new long[size];
			for (int i = 0; i < size; i++)
			{
				*(arr + i) = 0;
			}
		}
	}
	Array(const Array& other):size(other.size)
	{
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



	void Show(int num)const
	{
		cout << "====== Array " << num + 1 << " ========" << endl;
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << ' ';
			}
		}
		else cout << "     :EMPTY_ARRAY:" << endl;
		cout << endl;
	}



	~Array()
	{
		delete[] arr;
	}
};



void ShowAll(Array* array_list, int count)
{
	if (count == 0) cout << "Not found arrays." << endl;
	else
	{
		for (int i = 0; i < count; i++)
		{
			array_list[i].Show(i);
		}
		cout << endl;
	}
}
enum ADD_MENU { EMPTY = 1, BY_SIZE };
void AddArray(Array*& array_list, int& count)
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 2)
	{
		if (!isValidData) cout << "Error choice. Try again!" << endl;
		isValidData = false;
		cout << "1 - Add empty array" << endl;
		cout << "2 - Add array by size" << endl;
		cout << "Enter your choice : " << endl; cin >> choice;
	}
	switch (choice)
	{
	case ADD_MENU::EMPTY:  break;
	case ADD_MENU::BY_SIZE:  break;
	}
}



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
		cout << "3 - Show all array" << endl;
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
	int count = 0;
	Array* array_list;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::ADD:  break;
		case MENU::INIT:  break;
		case MENU::SHOW: ShowAll(array_list, count); break;
		case MENU::ADD_ELEM:  break;
		case MENU::RM_ELEM:  break;
		case MENU::SORT:  break;
		case MENU::GET_VALUES:  break;
		case MENU::EXIT: isExit = true;
		}
	}
	cout << "Good bye." << endl;
}