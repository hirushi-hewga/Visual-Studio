#include <iostream>
using namespace std;

struct BirthDate
{
	int day;
	int month;
	int year;
};

struct Location
{
	string city;
	string country;
};

class Student
{
	string name;
	string surname;
	string lastname;
	BirthDate birthDate;
	string phoneNumber;
	Location studentLocation;
	string nameEducationalPlace;
	Location educationalPlaceLocation;
	int groupNumber;
public:
	void Initialize()
	{
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
		birthDate.day = 0;
		birthDate.month = 0;
		birthDate.year = 0;
		phoneNumber = "no number";
		studentLocation.city = "no city";
		studentLocation.country = "no country";
		nameEducationalPlace = "no place name";
		educationalPlaceLocation.city = "no city";
		educationalPlaceLocation.country = "no country";
		groupNumber = 0;
	}
	void InitStudent()
	{
		cout << "Enter student name : "; cin >> name;
		cout << "Enter student surname : "; cin >> surname;
		cout << "Enter student lastname : "; cin >> lastname;
		cout << "Enter student birth date day : "; cin >> birthDate.day;
		cout << "Enter student birth date month : "; cin >> birthDate.month;
		cout << "Enter student birth date year : "; cin >> birthDate.year;
		cout << "Enter student phone number : "; cin >> phoneNumber;
		cout << "Enter student location city : "; cin >> studentLocation.city;
		cout << "Enter student location country : "; cin >> studentLocation.country;
		cout << "Enter student education place name : "; cin >> nameEducationalPlace;
		cout << "Enter education place location city : "; cin >> educationalPlaceLocation.city;
		cout << "Enter education place location country : "; cin >> educationalPlaceLocation.country;
	}
	void ShowStudent()
	{
		cout << "======================== Student ========================" << endl;
		cout << "Student fullname : " << name << ' ' << surname << ' ' << lastname << endl;
		cout << "Student birth date : " << birthDate.day << '.' << birthDate.month << '.' << birthDate.year << endl;
		cout << "Student Phone number : " << phoneNumber << endl;
		cout << "Student location : city -> " << studentLocation.city << " , country -> " << studentLocation.country << endl;
		cout << "Student education place name : " << nameEducationalPlace << endl;
		cout << "Student education place location : city -> " << educationalPlaceLocation.city << " , country -> " << educationalPlaceLocation.country << endl;
	}
};

int main()
{
	Student student;
	student.Initialize();
	student.ShowStudent();
	student.InitStudent();
	student.ShowStudent();
}