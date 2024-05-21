#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int num;
	Node* next;
	Node(Node* prev, int num, Node* next):prev(prev),num(num), next(next) {}
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
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
	}
};



int main()
{

}