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
		arr = new long[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}



	void Show()const
	{
		cout << "======== Array ========" << endl;
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << ' ';
			}
		}
		else cout << "      :EMPTY_ARRAY:" << endl;
		cout << endl;
	}
	void FillRandom()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 101 - 50;
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}
	void FillFromKeyboard()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Enter element : ";
			cin >> arr[i];
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}
	void FillDefault()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}



	~Array()
	{
		delete[] arr;
	}
};



enum FILL { RANDOM = 1, KEYBOARD, DEFAULT };
void Init(Array& arr)
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 3)
	{
		if (!isValidData) cout << "Error choice. Try again!" << endl;
		isValidData = false;
		cout << " - Fill random" << endl;
		cout << " - Fill from keyboard" << endl;
		cout << " - Init default (0)" << endl;
		cout << "Enter your choice : " << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case FILL::RANDOM: arr.FillRandom(); break;
	case FILL::KEYBOARD: arr.FillFromKeyboard(); break;
	case FILL::DEFAULT: arr.FillDefault();
	}
}




int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 7)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		isValidData = false;
		cout << endl;
		cout << "1 - Init array" << endl;
		cout << "2 - Show all array" << endl;
		cout << "3 - Add element to array" << endl;
		cout << "4 - Remove array element" << endl;
		cout << "5 - Sort array" << endl;
		cout << "6 - Get min max element, average value from array" << endl;
		cout << "7 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { INIT = 1, SHOW, ADD_ELEM, RM_ELEM, SORT, GET_VALUES, EXIT };
int main()
{
	srand(time(NULL));
	Array arr;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::INIT: Init(arr); break;
		case MENU::SHOW: arr.Show(); break;
		case MENU::ADD_ELEM:  break;
		case MENU::RM_ELEM:  break;
		case MENU::SORT:  break;
		case MENU::GET_VALUES:  break;
		case MENU::EXIT: isExit = true;
		}
	}
	cout << "Good bye." << endl;
}