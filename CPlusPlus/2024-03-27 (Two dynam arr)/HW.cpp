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
	int** arr = CreateArray(rows);



	for (int i = 0; i < *rows; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
}

int** CreateArray(int* size)
{
	int** arr = new int* [10];
	return arr;
}