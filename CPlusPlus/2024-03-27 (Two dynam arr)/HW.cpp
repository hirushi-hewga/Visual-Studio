#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	/*
	srand(time(NULL));
	int* rows = new int;
	int* cols = new int;
	cout << "Enter matrix rows: ";
	cin >> *rows;
	cout << "Enter matrix cols: ";
	cin >> *cols;
	int** arr = Create2DArray(rows, cols);

	Init2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);
	arr = AddRow2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);

	for (int i = 0; i < *rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	*/




	/*
	srand(time(NULL));
	int* rows = new int;
	int* cols = new int;
	cout << "Enter matrix rows: ";
	cin >> *rows;
	cout << "Enter matrix cols: ";
	cin >> *cols;
	int** arr = Create2DArray(rows, cols);

	Init2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);
	arr = DelRow2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);

	for (int i = 0; i < *rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	*/





	srand(time(NULL));
	int* rows = new int;
	int* cols = new int;
	cout << "Enter matrix rows: ";
	cin >> *rows;
	cout << "Enter matrix cols: ";
	cin >> *cols;
	int** arr = Create2DArray(rows, cols);

	Init2DArray(arr, rows, cols);
	Show2DArray(arr, rows, cols);
	arr = AddRow2DArrayIndex(arr, rows, cols);
	Show2DArray(arr, rows, cols);

	for (int i = 0; i < *rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
}

int** AddRow2DArrayIndex(int** arr, int* rows, int* cols)
{
	int index;
	cout << "Choice row index to add row: " << endl;
	cin >> index;

	(*rows)++;
	int** temp = new int* [*rows];
	for (int i = 0; i < *rows; i++)
	{
		*(temp + i) = new int[*cols];
	}
	InitArray(*(temp + index), cols);
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			*(*(temp + i + 1) + j) = *(*(arr + i) + j);
		}
	}
	for (int i = 0; i < *rows - 1; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

void InitArray(int* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		*(arr + i) = rand() % 80 + 20;
	}
}

int** DelRow2DArray(int** arr, int* rows, int* cols)
{
	(*rows)--;
	int** temp = new int* [*rows];
	for (int i = 0; i < *rows; i++)
	{
		*(temp + i) = new int[*cols];
	}
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			*(*(temp + i) + j) = *(*(arr + i + 1) + j);
		}
	}
	for (int i = 0; i < *rows + 1; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

int** AddRow2DArray(int** arr, int* rows, int* cols)
{
	(*rows)++;
	int** temp = new int* [*rows];
	for (int i = 0; i < *rows; i++)
	{
		*(temp + i) = new int[*cols];
	}
	InitArray(*temp, cols);
	for (int i = 0; i < *rows - 1; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			*(*(temp + i + 1) + j) = *(*(arr + i) + j);
		}
	}
	for (int i = 0; i < *rows-1; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	arr = temp;
	return arr;
}

void Show2DArray(int** arr, int* rows, int* cols)
{
	cout << "---------------------------------" << endl;
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			cout << *(*(arr + i) + j) << ' ';
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
}

void Init2DArray(int** arr, int* rows, int* cols)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			*(*(arr + i) + j) = rand() % 80 + 20;
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