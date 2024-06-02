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
				cout << " | " << word;
			}
			cout << " |" << endl;
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
	void AddWord(string word, string translate)
	{
		dic.insert(make_pair(word, list<string>{translate}));
	}
};



int main()
{
	Dictionary dictionary("English-Ukrainian");
	dictionary.AddWord("how", "yak");
	dictionary.Print();



}