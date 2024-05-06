#include <iostream>
using namespace std;

class Stack
{
	enum { EMPTY = -1 };
	int size;
	char* arr;
	int top;
public:
	Stack() = delete;
	Stack(int size)
	{
		this->size = size;
		arr = new char[size];
		top = EMPTY;
	}


	bool IsFull()const
	{
		return top < size - 1;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	void Push(char symbol)
	{
		if (!IsFull())
		{
			arr[++top] = symbol;
		}
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			top--;
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
	char Peek()const
	{
		return arr[top];
	}
	void ChangeMaxSize(int size)
	{
		if (size > 0)
		{
			char* temp = new char[size];
			int newTop = top < size ? top : size;
			if (top != EMPTY)
			{
				for (int i = 0; i <= newTop; i++)
				{
					temp[i] = arr[i];
				}
				delete[] arr;
			}
			arr = temp;
			top = newTop;
			this->size = size;
		}
	}


	~Stack()
	{
		if (arr != nullptr)
			delete[] arr;
	}
};


int main()
{
	Stack st(8);
	st.Push('a');
	st.Push('b');
	st.Push('c');
	st.Push('d');
	st.Push('e');
	st.Push('f');
	st.Pop();
	cout << st.GetCount() << endl;
}