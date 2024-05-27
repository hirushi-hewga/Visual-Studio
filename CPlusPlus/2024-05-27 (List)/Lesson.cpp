#include <iostream>
#include <list>
using namespace std;

void Print(list<int>& l1, list<int>& l2)
{
	int a = 5;
	int* pa = &a;
	cout << "List 1 : ";
	list<int>::iterator it;
	for (it = l1.begin(); it != l1.end(); it++)
	{
		cout << l1[i] << ' ';
	}
	cout << endl;
}

int main()
{
	list<int> list1, list2;
	for (int i = 0; i < 6; i++)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	Print(list1, list2);
	
	list1.assign({ 11,12,13,14,15,16,17,2,2,2,2,2 });
	Print(list1, list2);
	auto it = list1.begin();
	it++;
	it++;
	it++;
	list1.erase(it);
	list1.erase(list1.begin());
	Print(list1, list2);
	list1.remove(2);
	Print(list1, list2);
	list1.insert(list1.begin(), 5, 1);
	Print(list1, list2);
	list1.insert(list1.begin(), 100);
	Print(list1, list2);
	list1.insert(list1.begin(), { 7,8,9,10,11 });
	Print(list1, list2);
	list1.insert(list1.begin(), list2.begin(), list2.end());
	Print(list1, list2);

	// list1.resize(30);
	list1.resize(30, 44);
	Print(list1, list2);
	list1.splice(list1.end(), list2, list2.begin());
	Print(list1, list2);
	cout << "Size : " << list1.size() << endl;
}