#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node* next;
	Node(T value, Node* next):value(value),next(next) {}
};

template<typename T>
class List
{
	Node<T>* head;
public:
	List():head(nullptr) {}
	List(const List& other)
	{
		Node<T>* current = this->head;
		other.head = nullptr;
		while (current != nullptr)
		{
			Node<T>* newNode = new Node(current->value, other.head);
			other.head = newNode;
			current = current->next;
		}
	}
	List operator =(const List& other)
	{
		this->head = other.head;
		return *this;
	}


	void AddToHead(T value)
	{
		Node<T>* newNode = new Node<T>(value, head);
		head = newNode;
	}
	void AddToTail(T value)
	{
		Node<T>* newNode = new Node<T>(value, nullptr);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void DeleteFromHead()
	{
		Node<T>* current = head;
		head = head->next;
		delete current;
	}
	void DeleteFromTail()
	{
		if (head == nullptr) return;
		else if (head->next == nullptr)
		{
			delete head;
		}
		else
		{
			Node<T>* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void DeleteAll()
	{
		Node<T>* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void Show()const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->value << ' ';
			current = current->next;
		}
		cout << endl;
	}
	T Find(int pos)const
	{
		Node<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos == ++i) return current->value;
		}
		return 0;
	}
	void Add(int pos, T value)
	{
		Node<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos - 1 == ++i)
			{
				Node<T>* newNode = new Node<T>(value, current->next);
				current->next = newNode;
			}
			current = current->next;
		}
	}
	void Delete(int pos)
	{
		Node<T>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (pos - 1 == ++i)
			{
				Node<T>* next = current->next->next;
				delete current->next;
				current->next = next;
			}
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
			delete current;
		}
	}
};



int main()
{
	srand(time(NULL));
	List<int>* list;
	for (int i = 0; i < 5; i++)
	{
		list->AddToHead(rand() % 9 + 1);
	}
	list->Show();
}