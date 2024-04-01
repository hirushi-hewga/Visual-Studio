#include <iostream>
using namespace std;

struct Movie
{
	int id;
	char name[50];
	char director[50];
	char genre[50];
	float rating;
	float price;
	int views;
};

void Show(Movie m)
{
	cout << "================ Movie ================" << endl;
	cout << "\t\tId : " << m.id << endl;
	cout << "\t\tName : " << m.name << endl;
	cout << "\t\tDirector : " << m.director << endl;
	cout << "\t\tGenre : " << m.genre << endl;
	cout << "\t\tRating : " << m.rating << endl;
	cout << "\t\tPrice : " << m.price << endl;
	cout << "\t\tViews : " << m.views << endl;
}

void SearchByName(Movie m[], int size, char name[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].name, name) == 0)
			Show(m[i]);
	}
}

void SearchByGenre(Movie m[], int size, char genre[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].genre, genre) == 0)
			Show(m[i]);
	}
}

void SearchByDirector(Movie m[], int size, char director[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].director, director) == 0)
			Show(m[i]);
	}
}

void MostPopular(Movie m[], int size, char genre[])
{
	int max = 0;
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(m[i].genre, genre) == 0)
		{
			if (m[i].rating > max)
			{
				max = m[i].rating;
				maxIndex = i;
			}
		}
	}
}

void ChangeInfo(Movie m[], int size, int id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (m[i].id == id)
		{
			Show(m[i]);
			cout << "Name : ";
			cin.getline(m[i].name, 50);
			cout << "Genre : ";
			cin.getline(m[i].genre, 50);
			cout << "Director : ";
			cin.getline(m[i].director, 50);
			cout << "Rating : ";
			cin >> m[i].rating;
			cout << "Price : ";
			cin >> m[i].price;
			cout << "Views : ";
			cin >> m[i].views;
		}
	}
}

int main()
{
	const int size = 5;
	Movie movies[size]{
		{1,"Harry Potter","Alfonso Cuaron","Fantasy",3.72,150.49,250},
		{2,"Spider-Man","Sam Raine","Fantasy",4.5,100,30},
		{3,"Rambo","Ted","Detective",3.2,78.55,5},
		{4,"Venom","Ruben","Action",4.3,170.33,145},
		{5,"The hungers games","Gary Ross","Fantasy",4.8,190.36,200}
	};
	int choice;
	char name[50];
	do
	{
		cout << "\t\tMenu:" << endl;
		cout << "\tSearch by name            [1]" << endl;
		cout << "\tSearch by genre           [2]" << endl;
		cout << "\tSearch by director        [3]" << endl;
		cout << "\tThe most popular movie    [4]" << endl;
		cout << "\tShow all                  [5]" << endl;
		cout << "\tExit                      [0]" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			cout << "Enter name of movie : ";
			cin.getline(name, 50);//cin >> name;
			SearchByName(movies, size, name);
			break;
		case 2:
			cout << "Enter name of genre : ";
			cin.getline(name, 50);
			SearchByGenre(movies, size, name);
			break;
		case 3:
			cout << "Enter name of director : ";
			cin.getline(name, 50);
			SearchByDirector(movies, size, name);
			break;
		case 4:
			cout << "Enter genre of movie : ";
			cin.getline(name, 50);
			SearchByDirector(movies, size, name);
			break;
		case 5:
			for (int i = 0; i < size; i++)
			{
				Show(movies[i]); cout << endl;
			}
			break;
		case 6:
			int id;
			cout << "Enter id of movie : ";
			cin >> id;
			ChangeInfo(movies, size, id);
			break;
		case 0:
			cout << "Goodbye." << endl;
			break;
		default:
			cout << "Error choice." << endl; break;
		}
	} while (choice != 0);
}