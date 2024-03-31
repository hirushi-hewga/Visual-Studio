#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	int* rows = new int;
	int* cols = new int;
	cout << "Enter matrix rows: ";
	cin >> *rows;
	cout << "Enter matrix cols: ";
	cin >> *cols;
	int** arr = Create2DArray(rows, cols);

	Init2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);

	for (int i = 0; i < *rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
}

void Show2DArray(int** arr, int* rows, int* cols)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			cout << *(*(arr + i) + j) << ' ';
		}
		cout << endl;
	}
}

void Init2DArray(int** arr, int* rows, int* cols)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			*(*(arr + i) + j) = rand() % 79 + 20;
		}
	}
}

int** Create2DArray(int* rows, int* cols)
{
	int** arr = new int* [*rows];
	for (int i = 0; i < *rows; i++)
	{
		*(arr + i) = new int[*cols];
	}
	return arr;
}