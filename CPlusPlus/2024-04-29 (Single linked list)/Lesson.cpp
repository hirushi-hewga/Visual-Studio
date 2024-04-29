#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node(int value, Node* next):value(value),next(next) {}
};

class List
{
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(value, head);
		//newNode->value = value;
		//newNode->next = head;
		head = newNode;
	}
	void Print()
	{
		Node* current = head;
		while (current!= nullptr)
		{
			cout << "Value : " << head->value << endl;
			current = current->next;
		}
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete[] current;
		}
	}
};



int main()
{
	List list;
	for (int i = 0; i < 5; i++)
	{
		list.AddToHead(i);
	}
	list.Print();
}