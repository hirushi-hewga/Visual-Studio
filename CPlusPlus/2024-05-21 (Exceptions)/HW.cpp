#include <iostream>
#include <Windows.h>
using namespace std;

struct Node
{
	Node* prev;
	int value;
	Node* next;
	Node(Node* prev, int value, Node* next):prev(prev),value(value), next(next) {}
};

class List
{
	Node* head;
	Node* tail;
public:
	List():head(nullptr),tail(nullptr) {}


	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(nullptr, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void AddToTail(int value)
	{
		Node* newNode = new Node(nullptr, value, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void DeleteFromHead()
	{
		if (IsEmpty()) throw exception("List is empty");
		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty()) throw exception("List is empty");
		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void Show()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		system("cls");
	}
}
enum MENU { ADD_TO_HEAD = 1, ADD_TO_TAIL, DELETE_FROM_HEAD, DELETE_FROM_TAIL, PRINT_LIST, EXIT };
int main()
{
	cout << "123\n123\n123\n123" << endl;
	Sleep(1000);
	system("cls");
	cout << "123\n123\n123\n123" << endl;
}