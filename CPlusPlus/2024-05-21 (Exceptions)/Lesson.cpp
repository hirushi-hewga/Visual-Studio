#include <iostream>
#include <exception>
using namespace std;



float Divide(float a, float b)
{
	//try catch throw
	exception ex("Divide by zero");
	float res = 0;
	if (b == 0)
	{
		cout << "You can't divide by zero" << endl;
		throw ex;
	}
	else if (b == 2)
	{
		throw 404;
	}
	else if (b == 5)
	{
		throw "Divide by 5"
	}
	else
	{
		res = a / b;
		cout << "Res in function = " << res << endl;
		return res;
	}
}

void Login(const char* login, const char* password)
{
	if (strlen(password) < 6)
		throw exception("To small password");
	if (!isalpha(login[0]) || !islower(login[0]))
		throw exception("login is invalid");
	if (!isalpha(password[0]) || !islower(password[0]))
		throw exception("Password invalid");
	
	cout << "Loading..........." << endl;
}

int main()
{
	char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter login : "; cin >> login;
		cout << "Enter password : "; cin >> password;

		try
		{
			Login(login, password);
		}
		catch (exception ex)
		{
			cout << "Exception : " << ex.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown exception" << endl;
		}
	}





	/*float a, b;
	cout << "Enter a and b : ";
	cin >> a >> b;
	try
	{
		float res = Divide(a, b);
		cout << "Res in main = " << res << endl;
	}
	catch (exception ex)
	{
		cout << "Exception : " << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << "Exception : " << ex << endl;
	}
	catch (const char* ex)
	{
		cout << "Exception : " << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}
	cout << "Continue....................." << endl;
	cout << "Continue....................." << endl;
	cout << "Continue....................." << endl;
	cout << "Continue....................." << endl;*/
}