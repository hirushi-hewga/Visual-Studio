#include <iostream>
#include <vector>
#include <list>
#include <conio.h>
using namespace std;

struct Time
{
	int hours;
	int minutes;
};

struct Date
{
	int years;
	int months;
	int days;
	Time time;
	friend ostream& operator <<(ostream& out, const Date& other);
};
ostream& operator <<(ostream& out, const Date& other)
{
	out << other.days << '.' << other.months << '.' << other.years << " | " << other.time.hours << ':' << other.time.minutes << endl;
	return out;
}

struct Ticket
{
	string ticket_number;
	Date date_mail_sent;
	string order_address;
	int mail_weight;
	int cost_of_service;
	bool isDelivered;
	void Show()const
	{
		cout << "======== Ticket : " << ticket_number << " ========" << endl;
		cout << "Date mail sent : " << date_mail_sent << endl;
		cout << "Order address : " << order_address << endl;
		cout << "Mail weight : " << mail_weight << endl;
		cout << "Cost of service : " << cost_of_service << endl;
	}
};

class Customer
{
	string name;
	string surname;
	list<Ticket> ticket_of_mail;
public:
	Customer() : name("no name"), surname("no surname") {}

	void AddTicket(string ticket_number, Date date_mail_sent, string sender_address, int mail_weight, int cost_of_service)
	{
		ticket_of_mail.push_back(Ticket{ ticket_number, date_mail_sent, sender_address, mail_weight, cost_of_service, false });
	}
	void ShowTickets()const
	{
		system("cls");
		if (!ticket_of_mail.empty())
		{
			for (auto ticket : ticket_of_mail)
			{
				ticket.Show();
				cout << endl;
			}
		}
		else
		{
			cout << "Tickets not found!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}

	~Customer()
	{
		delete[] ticket_of_mail;
	}
};

class NovaPoshta
{
	string department_name;
	list<string> services;
	vector<string, list<Customer>> database_of_ordered_services;
	vector<string, list<Customer>> database_of_performed_services;
public:
	NovaPoshta() = delete;
	NovaPoshta(string department_name) : department_name(department_name) {}

	void ShowServices()const
	{

	}
	void ChangeService()
	{

	}
	void AddService()
	{

	}
	void DeleteService()
	{

	}
	void AddOrder()
	{

	}
	void ShowDataBaseOfOrderedServices()const
	{

	}
	void ShowDataBaseOfPerformedServices()const
	{

	}
	void SaveDataBaseOfOrderedServicesToFile()const
	{

	}
	void LoadDataBaseOfOrderedServicesFromFile()
	{

	}
	void SaveDataBaseOfPerformedServicesToFile()const
	{

	}
	void LoadDataBaseOfPerformedServicesFromFile()
	{

	}
};



int main()
{

}