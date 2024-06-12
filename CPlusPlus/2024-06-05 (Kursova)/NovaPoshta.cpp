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
	string service;
	int mail_weight;
	int cost_of_service;
	bool isDelivered;
	void Show()const
	{
		cout << "\t======== Ticket : " << ticket_number << " ========" << endl;
		cout << "\tDate mail sent : " << date_mail_sent << endl;
		cout << "\tOrder address : " << order_address << endl;
		cout << "\tMail weight : " << mail_weight << endl;
		cout << "\tCost of service : " << cost_of_service << endl;
	}
};

class Customer
{
	string name;
	string surname;
	list<Ticket> ticket_of_mail;
public:
	Customer() : name("no name"), surname("no surname") {}

	void AddTicket(string ticket_number, Date date_mail_sent, string sender_address, string service, int mail_weight, int cost_of_service)
	{
		ticket_of_mail.push_back(Ticket{ ticket_number, date_mail_sent, sender_address, service, mail_weight, cost_of_service, false });
	}
	void ShowTickets()const
	{
		system("cls");
		if (!ticket_of_mail.empty())
		{
			for (Ticket ticket : ticket_of_mail)
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
};

class NovaPoshta
{
	string department_name;
	list<string> services;
	vector<list<Customer>> database_of_ordered_services;
	vector<list<Customer>> database_of_performed_services;
public:
	NovaPoshta() = delete;
	NovaPoshta(string department_name) : department_name(department_name)
	{
		services.push_back("Courier delivery");
	}

	void ShowServices()const
	{
		system("cls");
		if (!services.empty())
		{
			for (string service : services)
			{
				cout << " - " << service << endl;
			}
		}
		else
		{
			cout << "Not found services" << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void ChangeService()
	{
		system("cls");
		if (!services.empty())
		{
			bool isValidData = true;
			int choice;
			int i;
			while (choice < 1 || choice > services.size())
			{
				i = 0;
				for (string service : services)
				{
					cout << i << " - " << service << endl;
				}
				cout << endl;
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				else isValidData = false;
				cout << "Choice a service to change : ";
				cin >> choice;
			}
			system("cls");
			string service_;
			cout << "Enter new service to change : ";
			cin >> service_;
			int i = 0;
			for (string& service : services)
			{
				if (++i == choice)
				{
					service = service_;
				}
			}
			cout << endl;
			cout << "The service has been successfully changed" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			_getch();
		}
		else
		{
			cout << "Not found services" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			_getch();
		}
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
	void DeliverTheOrder()
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