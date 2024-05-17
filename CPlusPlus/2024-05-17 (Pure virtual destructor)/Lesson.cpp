#include <iostream>
using namespace std;

class Person//abstract class 
{
protected:
    string name;
public:
    Person() :name("no name") {}
    Person(string name) :name(name) {}
    virtual void Print()const
    {
        cout << "Student : " << name << endl;
        cout << "\n____________________________________\n";
    }
    virtual ~Person() = 0 {}//pure virtual destructor

};
class Aspirant : public Person
{
    string* subjects;
    int countSubj;
public:
    Aspirant(string name, initializer_list<string> subjects) : Person(name)
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
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSubj; i++)
        {
            cout << subjects[i] << "  -  ";
        }
        cout << endl;
    }
    ~Aspirant()
    {
        if (subjects != nullptr)
            delete[]subjects;
    }
};

//int main()
//{
    //srand(time(0));
    ////Person st("Artem");
    ////st.Print();

    //Aspirant asp("Olga", { "Work with resourses", "Salles", "Test theme" });
    //asp.Print();
    //cout << "\n-------------------------------------------------------" << endl;

    //Person* groups[2]
    //{
    //    //new Person("Artem"),
    //    new Aspirant("Olga",{ "Work with resourses", "Salles", "Test theme"}),
    //    new Aspirant("Victor", { "Main window", "User experiance"})
    //};

    //for (int i = 0; i < 2; i++)
    //{
    //    groups[i]->Print();
    //    delete groups[i];
    //}
//}