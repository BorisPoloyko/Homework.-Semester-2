#include"DynamicArray.h"
#include<iostream>

using namespace std;

void console(const DynamicArray&);
bool assertThatAddIsTrue();

int main()
{
	DynamicArray array;
	array.add(5);
	array.add(4);
	array.add(2);
	array.add(1);
	array.add(8);
	cout << array.getLength() << endl;
	cout << array.findMax() << endl;
	cout << array.findMin() << endl;
	cout << array << endl;
	array.insertTo(1, 10);
	cout << array << endl;

	system("pause");

	return 0;
}

void console(const DynamicArray &array)
{
	for (int i = 0; i < array.getLength(); i++)
	{
		cout << array[i] << ' ';
	}
	
	cout << endl;
}

bool assertThatAddIsTrue()
{
	DynamicArray array1;

	int length = 10;

	for (int i = 0; i < length; i++)
	{
		array1.add(i);

	}

	bool areSameElements = true;

	for (int i = 0; i < length; i++)
	{
		if (array1[i] != i)
		{
			areSameElements = false;
			break;
		}
	}

	bool isRightLength = array1.getLength() == length;

	return isRightLength && areSameElements;
}
