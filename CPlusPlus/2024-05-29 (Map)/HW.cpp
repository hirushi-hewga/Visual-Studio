#include <iostream>
#include <string>
#include <list>
#include <map>
#include <conio.h>
using namespace std;

class Dictionary
{
	string name;
	map<string, list<string>> dic;
public:
	Dictionary(string name) : name(name) {}

	void Print()const
	{
		system("cls");
		cout << "-------- Dictionary : " << name << " --------" << endl;
		for (auto pair : dic)
		{
			cout << "Word : " << pair.first << " - ";
			for (string word : pair.second)
			{
				cout << word << ", ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "Press any key to continue : ";
		_getch();
	}
	void AddTranslate()
	{
		bool isValidData = true;
		string word = "";
		while (dic.find(word) == dic.end())
		{
			system("cls");
			for (auto pair : dic)
			{
				cout << "- " << pair.first << endl;
			}
			if (!isValidData) cout << "\nWord not found! Try again.\n";
			isValidData = true;
			cout << endl;
			cout << "Enter word : ";
			getline(cin, word);
		}

		system("cls");
		string translate = "";
		do
		{
			cout << "Enter translate : ";
			getline(cin, translate);
			dic[word].push_back(translate);
		} while (!translate.empty());
	}
	void AddTranslate_(string word, string translate)
	{
		if (dic.find(word) == dic.end())
			cout << "Word not found!" << endl;
		else
			dic[word].push_back(translate);
	}
	void AddWord(string word, string translate)
	{
		dic.insert(make_pair(word, list<string>{translate}));
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 8)
	{
		system("cls");
		cout << "1 - Add word" << endl;
		cout << "2 - Find the word" << endl;
		cout << "3 - Add translation" << endl;
		cout << "4 - Delete word" << endl;
		cout << "5 - Show all words" << endl;
		cout << "6 - Save to file" << endl;
		cout << "7 - Load from file" << endl;
		cout << "8 - Exit" << endl;
		if (!isValidData) cout << "\nError choice! Try again\n";
		isValidData = false;
		cout << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { ADD_PAIR = 1, SEARCH_BY_WORD, ADD_TRANSLATE, DELETE_WORD, SHOW, SAVE, LOAD, EXIT };
int main()
{
	Dictionary dictionary("English-Ukrainian");
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case ADD_PAIR:  break;
		case SEARCH_BY_WORD:  break;
		case ADD_TRANSLATE: dictionary.AddTranslate(); break;
		case DELETE_WORD:  break;
		case SHOW: dictionary.Print(); break;
		case SAVE:  break;
		case LOAD:  break;
		case EXIT: isExit = true;
		}
	}




	/*
	Dictionary dictionary("English-Ukrainian");
	dictionary.AddWord("light", "svitlo");
	dictionary.AddWord("great", "chudovo");
	dictionary.AddWord("just", "prosto");
	dictionary.AddWord("open", "vidchuneno");
	dictionary.AddWord("neither", "ni");
	dictionary.AddWord("because", "oskilku");
	dictionary.AddWord("left", "zliva");
	dictionary.AddWord("alive", "badioruy");
	dictionary.AddWord("quality", "yakist");
	dictionary.AddWord("may", "mozna");
	dictionary.Print();
	dictionary.AddTranslate_("light", "lehkiy");
	dictionary.AddTranslate_("great", "velukiy");
	dictionary.AddTranslate_("just", "zaraz");
	dictionary.AddTranslate_("open", "otvir");
	dictionary.AddTranslate_("neither", "zoden");
	dictionary.AddTranslate_("because", "bo");
	dictionary.AddTranslate_("left", "pokunytuy");
	dictionary.AddTranslate_("alive", "zuvuy");
	dictionary.AddTranslate_("quality", "vlastuvist");
	dictionary.AddTranslate_("may", "traven");
	dictionary.Print();

	dictionary.AddWord("save", "vryatuvaty");
	dictionary.AddTranslate("save");
	dictionary.Print();
	*/
}