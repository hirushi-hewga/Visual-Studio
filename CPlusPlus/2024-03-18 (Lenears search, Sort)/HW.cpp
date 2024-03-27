#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	srand(time(NULL));
	const int size = 10;
	int arr[size]{};
	InitArray(arr, size);
	cout << *arr;















	/*
	int number, pow;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter power of number: ";
	cin >> pow;
	cout << "Power of number " << number << " --> " << PowerOfNumber(number, pow) << endl;
	*/
}

void InitArray(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(parr + i) = rand() % 90 + 10;
	}
}

//void InsertSort(int arr[], int size, int value = 1)
//{
//	//11 4 2 7 3 11 8 9 6 
//	int temp;
//	int j;
//	for (int i = 0; i < size; i++)
//	{
//		//i = 1;????
//		temp = arr[i];//4
//		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
//		{
//			//j = 0
//			//arr[j + 1] = 4
//			arr[j + 1] = arr[j];
//		}
//		arr[j + 1] = temp;
//	}
//
//}

int PowerOfNumber(int number, int pow)
{
	pow--;
	if (pow == 0) return number;
	return number * PowerOfNumber(number, pow);
}