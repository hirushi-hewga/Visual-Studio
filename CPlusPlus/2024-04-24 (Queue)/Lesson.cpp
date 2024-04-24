#include <iostream>
using namespace std;


class Queue
{
	int* arr;
	int maxSize;
	int top;
public:
	Queue() = delete;
	Queue(int maxSize)
	{
		arr = new int[maxSize];
		top = 0;
	}



	bool IsFull()const
	{
		return top == maxSize;
	}
	bool IsEmpty()const
	{
		return top == 0;
	}
	void Enqueue(int element)
	{
		if (!IsFull())
		{
			arr[top++] = element;
		}
	}
	int Dequeue()
	{
		if (!IsEmpty())
		{
			int first = arr[0];
			for (int i = 1; i < top; i++)
			{
				arr[i - 1] = arr[i];
			}
			//simple queue
			top--;
			return first;
		}
	}
	int GetCount()const
	{
		return top;
	}
	void Clear()
	{
		top = 0;
	}
	int Peek()
	{
		if (IsEmpty()) return 0;
		return arr[0];
	}
	void Print()const
	{
		for (int i = 0; i < top; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}



	~Queue()
	{
		delete[] arr;
	}
};



int main()
{
	Queue q(25);
	for (int i = 0; i < 10; i++)
	{
		q.Enqueue(rand() % 20);
	}
	q.Print();

	while (!q.IsEmpty())
	{
		cout << "Element : " << q.Dequeue() << endl;
	}
}