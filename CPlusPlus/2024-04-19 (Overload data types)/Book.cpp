#include "Book.h"

Book::Book()
{
	title = "no title";
	year = 1;
	author = "no author";
	pages = 0;
	genre = NONE;
}

void Book::ShowInfo()
{

	switch (genre)
	{
	case NONE: cout << "NONE" << endl; break;
	case HISTORY: cout << "HISTORY" << endl; break;
	case FANTASY: cout << "FANTASY" << endl; break;
	case DRAMA: cout << "DRAMA" << endl; break;
	case ROMAN: cout << "ROMAN" << endl; break;
	case COMEDY: cout << "COMEDY" << endl; break;
	case PROGRAMMING: cout << "PROGRAMMING" << endl; break;
	case POLITICAL: cout << "POLITICAL" << endl; break;
	case SCIENCE_FICTION: cout << "POLITICAL" << endl;
	}
}
