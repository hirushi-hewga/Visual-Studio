#include <iostream>
using namespace std;

template<typename T>
class Queue
{
public:
	struct Element {
		T value;
		int priority;
	};
	/*ostream& operator << (ostream& out, const Element& el)
	{
		out << el.value << "  :  " << el.priority << " ";
		return out;
	}*/

private:
	Element* arr;
	int size;
public:
	Queue() :arr(nullptr), size(0) {}
	~Queue()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	void Enqueue(T value, int pr)
	{
		int index = 0;
		while (index < size && arr[index].priority < pr)
		{
			index++;
		}
		size++;
		Element* temp = new Element[size];
		for (int i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = Element{ value, pr };
		for (int i = index; i < size - 1; i++)
		{
			temp[i + 1] = arr[i];
		}
		if (arr != nullptr)
		{
			delete[]arr;
		}
		arr = temp;
	}
	bool IsEmpty()const
	{
		return size == 0;
	}
	Element Dequeue()
	{
		if (!IsEmpty())
		{
			Element first = arr[0];
			for (int i = 0; i < size; i++)
			{
				arr[i] = arr[i + 1];

			}
			size--;
			return first;
		}
		return Element();
	}
	void Print()const
	{
		cout << "--------------- Queue with priority ----------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i].value << " " << arr[i].priority << " | ";
		}
		cout << endl;
		cout << "____________________________________________________" << endl;
	}
};



int main()
{
	Queue<char> q;
	//Element<T> el = { 'A', 1};
	//q.Enqueue(el);

	q.Enqueue('A', 1);
	q.Enqueue('B', 2);
	q.Enqueue('C', 3);
	q.Enqueue('G', 5);
	q.Enqueue('K', 8);
	q.Enqueue('N', 13);
	q.Print();
	q.Enqueue('D', 4);
	q.Print();
	while (!q.IsEmpty())
	{
		cout << "Element : " << q.Dequeue().value << endl;
	}
}