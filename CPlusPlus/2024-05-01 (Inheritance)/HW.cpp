#include <iostream>
using namespace std;

struct Fullname
{
	string name;
	string surname;
	string lastname;
	Fullname(string name, string surname, string lastname):name(name),surname(surname),lastname(lastname) {}
};

class Student
{
protected:
	Fullname fullname;
	int age;
	Student() = delete;
	Student(string name, string surname, string lastname, int age):fullname(name, surname, lastname), age(age) {}


	void Print()const
	{
		cout << "Fullname : " << fullname.name << ' ' << fullname.surname << ' ' << fullname.lastname << endl;
		cout << "Age : " << age << endl;
	}
};

class Aspirant : public Student
{
	int sheets;
public:
	Aspirant(string name, string surname, string lastname, int age, int sheets):sheets(sheets), Student(name, surname, lastname, age) {}

};



int main()
{

}