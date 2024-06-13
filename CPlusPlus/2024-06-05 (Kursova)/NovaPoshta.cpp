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
		cout << ". ======== Ticket : " << ticket_number << " ========" << endl;
		cout << "   Date mail sent : " << date_mail_sent << endl;
		cout << "   Order address : " << order_address << endl;
		cout << "   Mail weight : " << mail_weight << endl;
		cout << "   Cost of service : " << cost_of_service << endl;
	}
};

class Client
{
	string name;
	string surname;
	list<Ticket> ticket_of_mail;
public:
	Client() = delete;
	Client(string name, string surname) : name(name), surname(surname) {}

	int size()const
	{
		return ticket_of_mail.size();
	}
	bool empty()const
	{
		return ticket_of_mail.size() == 0;
	}
	Ticket& GetTicket(int index)
	{
		auto it = ticket_of_mail.begin();
		advance(it, index);
		return (*it);
	}
	void AddTicket(string ticket_number, Date date_mail_sent, string sender_address, string service, int mail_weight, int cost_of_service)
	{
		ticket_of_mail.push_back(Ticket{ ticket_number, date_mail_sent, sender_address, service, mail_weight, cost_of_service, true });
	}
	bool ShowTickets()const
	{
		if (!ticket_of_mail.empty())
		{
			cout << "======== " << name << ' ' << surname << " ========" << endl;
			int i = 0;
			for (Ticket ticket : ticket_of_mail)
			{
				cout << ++i;
				ticket.Show();
				cout << endl;
			}
			cout << endl;
			return true;
		}
		return false;
	}
	void ShowClient()const
	{
		cout << " - " << name << ' ' << surname << " | Tickets : " << ticket_of_mail.size() << endl;
	}
};

class NovaPoshta
{
	string department_name;
	list<string> services;
	vector<Client> database_of_ordered_services;
	vector<Client> database_of_performed_services;
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
		}
		else cout << "Not found services" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddService()
	{
		system("cls");
		string newService;
		cout << "Enter new service to add : ";
		cin >> newService;
		services.push_back(newService);
		cout << endl;
		cout << "Service added" << endl;
		cout << endl;
		cout << "The service has been successfully added" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void DeleteService()
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
				cout << "Choice a service to delete : ";
				cin >> choice;
			}
			auto it = services.begin();
			advance(it, choice - 1);
			services.erase(it);
			cout << endl;
			cout << "The service has been successfully deleted" << endl;
		}
		else cout << "Not found services" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddClient()
	{
		system("cls");
		string name, surname;
		cout << "Enter client name : ";
		cin >> name;
		cout << "Enter client surname : ";
		cin >> surname;
		database_of_ordered_services.push_back(Client(name, surname));
		database_of_performed_services.push_back(Client(name, surname));
		cout << endl;
		cout << "Client added" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowClients()const
	{
		system("cls");
		if (!database_of_ordered_services.empty())
		{
			for (Client client : database_of_ordered_services)
			{
				client.ShowClient();
			}
		}
		else cout << "Clients not found" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddTicket()
	{
		system("cls");
		if (!services.empty() && !database_of_ordered_services.empty())
		{
			string ticket_number, sender_address, service;
			int years, months, days, hours, minutes;
			int mail_weight, cost_of_service;

			int client = 0;
			bool isValidData = true;
			while (client < 1 || client > database_of_ordered_services.size())
			{
				int i = 0;
				for (Client client_ : database_of_ordered_services)
				{
					cout << ++i;
					client_.ShowClient();
				}
				cout << "Choice client : ";
				cin >> client;
			}
			auto it = database_of_ordered_services.begin();
			advance(it, client - 1);

			cout << "Enter ticket number : ";
			cin >> ticket_number;

			cout << "Enter sender address : ";
			cin >> sender_address;

			int choice = 0;
			isValidData = true;
			while (choice < 1 || choice > services.size())
			{
				int i = 0;
				for (string service_ : services)
				{
					cout << ++i << " - " << service_ << endl;
				}
				cout << "Choice service : ";
				cin >> choice;
			}
			auto it_ = services.begin();
			advance(it_, choice - 1);
			service = (*it_);

			cout << "Enter year mail sent : ";
			cin >> years;
			cout << "Enter months mail sent : ";
			cin >> months;
			cout << "Enter days mail sent : ";
			cin >> days;
			cout << "Enter hours mail sent : ";
			cin >> hours;
			cout << "Enter minutes mail sent : ";
			cin >> minutes;

			cout << "Enter mail weight : ";
			cin >> mail_weight;

			cout << "Enter cost of service : ";
			cin >> cost_of_service;

			(*it).AddTicket(ticket_number, Date{ years, months, days, {hours, minutes} }, sender_address, service, mail_weight, cost_of_service);

			cout << "Ticket added" << endl;
		}
		else
		{
			if (services.empty()) cout << "Services not found" << endl;
			if (database_of_ordered_services.empty()) cout << "Clients not found" << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void DeliverTheOrder()
	{
		if (!database_of_ordered_services.empty())
		{
			int i;
			int choice = 0;
			vector<Client>::iterator it;
			while (true)
			{
				try
				{
					system("cls");
					while (choice < 1 || choice > database_of_ordered_services.size())
					{
						i = 0;
						for (Client client : database_of_ordered_services)
						{
							cout << ++i; client.ShowClient();
						}
						cout << endl;
						cout << "Choice client to deliver the order : ";
						cin >> choice;
					}
					it = database_of_ordered_services.begin();
					advance(it, choice - 1);
					if ((*it).empty()) throw exception("not found for this client");
					break;
				}
				catch (exception ex)
				{
					system("cls");
					cout << ex.what() << endl;
					cout << endl;
					cout << "Press any key to repeat : ";
					_getch();
				}
				catch (...)
				{
					system("cls");
					cout << "Unknown exception" << endl;
					cout << endl;
					cout << "Press any key to repeat : ";
					_getch();
				}
			}
			auto it_ = database_of_performed_services.begin();
			advance(it_, choice - 1);
			choice = 0;
			bool isValidData = true;
			system("cls");
			while (choice < 1 || choice >(*it).size())
			{
				(*it).ShowTickets();
				if (!isValidData)
				{
					cout << "Error choice! Try again." << endl;
					cout << endl;
				}
				cout << "Choice a ticket for delivery : ";
				cin >> choice;
			}
			Ticket& ticket = (*it).GetTicket(choice - 1);


		}
		else
		{
			system("cls");
			cout << "No tickets found for undelivered orders!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowDataBaseOfOrderedServices()const
	{
		system("cls");
		if (!database_of_ordered_services.empty())
		{
			bool isFoundTicket = false;
			for (Client customer : database_of_ordered_services)
			{
				if (customer.ShowTickets())
				{
					isFoundTicket = true;
				}
			}
			if (!isFoundTicket)
			{
				cout << "No tickets found for undelivered orders!" << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "No tickets found for undelivered orders!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}
	void ShowDataBaseOfPerformedServices()const
	{
		system("cls");
		if (!database_of_performed_services.empty())
		{
			bool isFoundTicket = false;
			for (Client customer : database_of_performed_services)
			{
				if (customer.ShowTickets())
				{
					isFoundTicket = true;
				}
			}
			if (!isFoundTicket)
			{
				cout << "No tickets found for delivered orders!" << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "No tickets found for delivered orders!" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		_getch();
	}
	void SaveDataBaseOfOrderedServicesToFile()const
	{

	}
	void SaveDataBaseOfPerformedServicesToFile()const
	{

	}
	void LoadDataBaseOfOrderedServicesFromFile()
	{

	}
	void LoadDataBaseOfPerformedServicesFromFile()
	{

	}
};



int main()
{

}