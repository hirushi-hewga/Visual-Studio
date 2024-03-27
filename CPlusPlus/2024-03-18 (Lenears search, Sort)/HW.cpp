#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	/*
	srand(time(NULL));
	const int size = 10;
	int arr[size]{};
	InitArray(arr, size);
	ShowArray(arr, size);
	int choice;
	cout << "1 - sortuvannya za zrostannyam" << endl;
	cout << "2 - sortuvannya za spadannyam" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	InsertSort(arr, size, choice - 1);
	ShowArray(arr, size);
	*/





	srand(time(NULL));
	const int size = 10;
	int arr[size]{};
	InitArray2(arr, size);
	ShowArray(arr, size);
	int* sortedArray = Function(arr, size);
	ShowArray(sortedArray, size);














	/*
	int number, pow;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter power of number: ";
	cin >> pow;
	cout << "Power of number " << number << " --> " << PowerOfNumber(number, pow) << endl;
	*/
}

void ShowArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(parr + i) << ' ';
	}
	cout << endl;
}

void InitArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 90 + 10;
	}
}

void InitArray2(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 41 - 20;
	}
}

void InsertSort(int arr[], int size, int value)
{
	if (value != 1 && value != 0) value = 1;
	if (value == 0)
	{
		int temp;
		int j;
		for (int i = 0; i < size; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
	else if (value == 1)
	{
		int temp;
		int j;
		for (int i = 0; i < size; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] < temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

int* Function(int arr[], int size)
{
	int maxElement, minElement;
    for (minElement = size - 1; minElement >= 0; minElement--) if (arr[minElement] < 0) break;
    for (maxElement = 0; maxElement <= size - 1; maxElement++) if (arr[maxElement] < 0) break;
	return InsertSort2(arr, maxElement - maxElement, minElement + 1);
}

int* InsertSort2(int arr[], int size, int minElement)
{
	int temp;
	int j;
	for (int i = minElement; i < size - 1; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= minElement && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	return arr;
}

int PowerOfNumber(int number, int pow)
{
	pow--;
	if (pow == 0) return number;
	return number * PowerOfNumber(number, pow);
}