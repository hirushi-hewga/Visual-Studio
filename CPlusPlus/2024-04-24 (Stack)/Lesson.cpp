#include <iostream>
using namespace std;

//class Stack
//{
//	enum {EMPTY = -1, FULL = 9};
//	int arr[FULL + 1];
//	int top;
//public:
//	Stack()
//	{
//		top = EMPTY;
//	}
//	Stack(const Stack& other) = delete;
//
//
//
//	bool IsFull()const
//	{
//		return top == FULL;
//	}
//	bool Push(int elem)
//	{
//		if (!IsFull())
//		{
//			arr[++top] = elem;
//			return true;
//		}
//		return false;
//	}
//	bool IsEmpty()const
//	{
//		return top == EMPTY;
//	}
//	int Pop()
//	{
//		if (!IsEmpty())
//		{
//			return arr[top--];
//		}
//	}
//	int GetCount()const
//	{
//		return top + 1;
//	}
//	void Print()const
//	{
//		for (int i = 0; i <= top; i++)
//		{
//			cout << arr[i] << ' ';
//		}cout << endl;
//	}
//};
class MyClass
{
	//default delete
	//default constructor
	//copy constructor
	//destructor
	//operator =
};
class Stack
{
	int size;
	int* arr;
	int top;
	enum {EMPTY = -1};
public:
	Stack() = delete;
	Stack(int size): size(size)
	{
		top = EMPTY;
		arr = new int[size];
	}



	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(int value)
	{
		if (!IsFull())
		{
			arr[++top] = value;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[top--];
		}
	}
	int Peek()const
	{
		if (!IsEmpty())
		{
			return arr[top];
		}
	}
	int GetCount()const
	{
		return top + 1;
	}
	void Clear()
	{
		top = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}



	~Stack()
	{
		delete[] arr;
	}
};



bool IsValidCode(string code)
{
	Stack st(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st.Push(1);
		}
		if (symbol == '}')
		{
			if (st.IsEmpty()) return false;
			st.Pop();
		}
	}
}
int main()
{
	string code = "class Stack { void Print() { if(){} } };";




	/*
	srand(time(NULL));
	Stack st(20);
	while (!st.IsFull())
	{
		st.Push(rand() % 100);
	}

	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "Element : " << st.Pop() << endl;
	cout << "Count : " << st.GetCount() << endl;
	while (!st.IsEmpty())
	{
		cout << "Element : " << st.Pop() << endl;
	}
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	*/

	/*
	st.Push(10);
	st.Push(7);
	st.Push(5);
	st.Push(4);
	st.Push(10);
	st.Push(7);
	st.Push(5);
	st.Push(4);
	*/
}