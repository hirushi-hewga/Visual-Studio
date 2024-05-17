#include <iostream>
using namespace std;

class Student
{
	string name;
	string spetialization;
	int* marks;
	int markCount;
public:
	Student():name("no name"),spetialization("no specialization"), marks(nullptr), markCount(0) {}
	Student(string name, string spetialization) :name(name), spetialization(spetialization)
	{
		markCount = rand() % 10 + 1;
		marks = new int[markCount];
		for (int i = 0; i < markCount; i++)
		{
			marks[i] = rand() % 4 + 9;
		}
	}


	virtual void Print()const
	{
		cout << "Student : " << name << endl;
		cout << "Spetialization : " << spetialization << endl;
		cout << "Marks : ";
		for (int i = 0; i < markCount; i++)
		{
			cout << marks[i];
		}
		cout << "\n----------------------------------------\n";
	}


	~Student()
	{
		if (marks != nullptr)
			delete[] marks;
	}
};

class Aspirant : public Student
{
	string* subjects;
	int countSubj;
public:
	Aspirant(string name, string sp, initializer_list<string> subjects):Student(name, sp)
	{
		this->countSubj = subjects.size();
		this->subjects = new string[countSubj];
		int i = 0;
		for (string s : subjects)
		{
			this->subjects[i] = s;
			i++;
		}
	}


	void Print()const override
	{
		Student::Print();
		cout << "Subject : ";
		for (int i = 0; i < countSubj; i++)
		{
			cout << subjects[i] << ' ';
		}
		cout << "theme" << endl;
	}


	~Aspirant()
	{
		if (subjects != nullptr)
			delete[] subjects;
	}
};



int main()
{
	srand(time(NULL));
	Student st("Artem", "Programmer");
	st.Print();

	Aspirant asp( "Olga", "Managment", { "Work with resourses", "Salles", "Test" } );
	asp.Print();


	Student* group[3]
	{
		new Student("Artem", "Programmer"),
		new Aspirant("Olga", "Management", { "Work with resourses", "Salles", "Test theme" }),
		new Aspirant("Victor", "UA/UX", { "Main window", "User experiance" })
	};

	for (int i = 0; i < 3; i++)
	{
		group[i]->Print();
		delete group[i];
	}
}