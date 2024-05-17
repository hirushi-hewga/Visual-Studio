#include <iostream>
using namespace std;

class Student
{
	string name;
	int* marks;
	int markCount;
public:
	Student():name("no name"),marks(nullptr),markCount(0) {}
	Student(string name) :name(name)
	{
		markCount = rand() % 10 + 1;
		marks = new int[markCount];
		for (int i = 0; i < markCount; i++)
		{
			marks[i] = rand() % 12 + 1;
		}
	}
	void Print()const
	{
		cout << "Student : " << name << endl;
		cout << "Marks : ";
		for (int i = 0; i < markCount; i++)
		{
			cout << marks[i];
		}
		cout << "\n----------------------------------------\n";
	}
};



int main()
{
	srand(time(NULL));
	Student st("Artem");
	st.Print();
}