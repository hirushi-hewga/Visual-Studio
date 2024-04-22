#include <iostream>
using namespace std;

class Array
{
	int size;
	long* arr;
public:
	Array() :size(0), arr(nullptr) {}
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



	void Show()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
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
	ArrayList() :count(0), array(nullptr) {}



	void Add()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 2)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			cout << endl;
			cout << "1 - Add empty array" << endl;
			cout << "2 - Add array by size" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		if (choice == 1)
		{
			Array* temp = new Array[count + 1];
			for (int i = 0; i < count; i++)
			{
				temp[i] = Array(array[i]);
			}
			temp[count] = Array();
			if (array != nullptr)
				delete[] array;
			array = temp;
			count++;
		}
		if (choice == 2)
		{
			Array* temp = new Array[count + 1];
			for (int i = 0; i < count; i++)
			{
				temp[i] = Array(array[i]);
			}
			int size = 0;
			cout << "Enter array size : "; cin >> size;
			temp[count] = Array(size);
			if (array != nullptr)
				delete[] array;
			array = temp;
			count++;
		}
	}
	void Show()const
	{
		for (int i = 0; i < count; i++)
		{
			cout << "======== Array " << i + 1 << " ========" << endl;
			array[i].Show();
			cout << endl;
		}
	}
	void Init()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			cout << endl;
			cout << "1 - Init random" << endl;
			cout << "2 - Init with klaviatura" << endl;
			cout << "3 - Default Init (0)" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
	}



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
	ArrayList array_list;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::ADD: array_list.Add(); break;
		case MENU::INIT: array_list.Init(); break;
		case MENU::SHOW: array_list.Show(); break;
		case MENU::ADD_ELEM:  break;
		case MENU::RM_ELEM:  break;
		case MENU::SORT:  break;
		case MENU::GET_VALUES:  break;
		case MENU::EXIT: isExit = true;
		}
	}
	cout << "Good bye." << endl;
}