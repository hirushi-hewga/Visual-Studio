#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

class Dictionary
{
	string name;
	map<string, list<string>> dic;
public:
	Dictionary(string name) : name(name) {}

	void Print()const
	{
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
	}
	void AddTranslate(string word)
	{
		if (dic.find(word) == dic.end())
		{
			cout << "Word not found!" << endl;
		}
		else
		{
			string translate = "";
			do
			{
				cout << "Enter translate : ";
				getline(cin, translate);
				dic[word].push_back(translate);
			} while (!translate.empty());
		}
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



int main()
{
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



}