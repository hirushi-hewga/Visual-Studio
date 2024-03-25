#include <iostream>
using namespace std;

void Test()
{
	const int size = 10;
	int arr[size];
}

void Test2()
{
	int size = 5;
	int* arr = new int[size];
	delete[] arr;
}

void InitArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 91 + 10;
	}
}

void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	int size;
	cout << "Enter size of arr: ";
	cin >> size;
	int* arr = new int[size];
	InitArray(arr, size);
	ShowArray(arr, size);
	delete[] arr;




	//Test2();

	//int a = 10;
	//int* pa = new int(3);
	//int* pb = new int;

	//int b;//trash
	//b = 5;

	//1
	//int* ptr = 0;//trash
	//if (ptr != 0){   }
	
	//2
	//int* ptr = NULL;//trash
	//if (ptr != 0) {}

	//3
	//int* ptr = nullptr;//trash
	//if (ptr != nullptr) {   }

	/*
	int a = 10;
	int b;//trash
	b = 5;
	int* pa = new int(3);
	int* pb = new int;
	int* pc = nullptr;
	cout << *pc << endl;//error
	*pb = 5;
	pc = new int(12);

	cout << *pa << endl;
	cout << *pb << endl;
	cout << *pc << endl;

	delete pc;
	pc = new int(5);
	
	delete pa;
	delete pb;
	delete pc;
	*/
}