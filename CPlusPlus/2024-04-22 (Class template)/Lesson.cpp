#include <iostream>
using namespace std;

class Point{};
class MyClass
{
	int* collection;
	int size;
	Point point;
public:
	
};



template<typename T_arr>

T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}



int main()
{
	const int size = 10;
	float numbers[size] = {5, 8, 45, 7, 96, 3, 25, 85, 96, 12};
	cout << "Max : " << GetMax(numbers, size) << endl;
	string colors[5] = { "A", "AA", "AAA", "AAAA", "W" };
	cout << "Max : " << GetMax(colors, 5) << endl;

	string names[6] = { "Ilya", "Sasha", "Nikita", "Sergiy", "Ivan", "Max" };
	cout << "Max : " << GetMax(names, 6) << endl;
}