#include <iostream>
using namespace std;

template<typename T>
class Stack
{
	enum { EMPTY = -1 };
	int size;
	int top;
	T* arr;
public:
	Stack() = delete;
	Stack(int size):size(size)
	{
		top = EMPTY;
		arr = new T[size];
	}
	Stack(const initializer_list<int> list)
	{
		top = EMPTY;
		this->size = list.size();
		arr = new T[size];
		for (T value : list)
		{
			arr[++top] = value;
		}
	}


	bool IsFull()const
	{
		return top == size - 1;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	void Push(T value)
	{
		if (!IsFull())
		{
			arr[++top] = value;
		}
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			top--;
		}
	}
	int Peek()const
	{
		return arr[top];
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
	Stack<int> st1(20);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st1.Push(1);
		}
		if (symbol == '[')
		{
			st1.Push(2);
		}
		if (symbol == '(')
		{
			st1.Push(3);
		}
		if (symbol == '}')
		{
			if (st1.IsEmpty() || st1.Peek() != 1) return false;
			st1.Pop();
		}
		if (symbol == ']')
		{
			if (st1.IsEmpty() || st1.Peek() != 2) return false;
			st1.Pop();
		}
		if (symbol == ')')
		{
			if (st1.IsEmpty() || st1.Peek() != 3) return false;
			st1.Pop();
		}
	}
	return st1.IsEmpty();
}



int main()
{
	string code1 = "({x - y - z} * [x + 2y] - (z + 4x))";
	string code2 = "([x - y - z} * [x + 2y) - {z + 4x))";
	if (IsValidCode(code1))
		cout << "Code 1 is valid" << endl;
	else
		cout << "Code 1 is invalid" << endl;
	if (IsValidCode(code2))
		cout << "Code 2 is valid" << endl;
	else
		cout << "Code 2 is invalid" << endl;
}