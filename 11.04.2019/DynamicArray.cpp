#include "DynamicArray.h"
#include<iostream>

using namespace std;

DynamicArray::DynamicArray() : innerArray(nullptr)
{
	this->innerArray = allocateMemory(defaultCapacity);
	this->capacity = defaultCapacity;
	this->length = 0;
}

DynamicArray::DynamicArray(int n) : innerArray(nullptr)
{
	this->innerArray = allocateMemory(n);
	this->capacity = n;
	this->length = 0;
}

DynamicArray::DynamicArray(const DynamicArray &array)
{
	this->innerArray = allocateMemory(array.capacity);
	this->capacity = array.capacity;
	this->length = array.length;

	for (unsigned int i = 0; i < this->length; i++)
	{
		this->innerArray[i] = array.innerArray[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] innerArray;
}

void DynamicArray::setLength(int n)
{
	if (n < 0)
	{
		throw invalid_argument("Length should be greater than 0");
	}

	this->length = n;
}

int DynamicArray::getLength() const
{
	return this->length;
}

void DynamicArray::add(int item)
{
	int length = this->getLength();

	if (this->capacity - length <= 0)
	{
		this->capacity *= growthFactor;
		resizeMemory(innerArray, length, capacity);
	}

	this->innerArray[length] = item;
	setLength(length + 1);
}

void DynamicArray::remove(int n)
{
	int length = this->getLength();

	for (int i = n + 1; i < length; i++)
	{
		(*this)[i - 1] = innerArray[i];
	}

	setLength(length - 1);
}

//DynamicArray DynamicArray::operator=(const DynamicArray &source)
//{
//	return DynamicArray(source);
//}

int& DynamicArray::operator[](int n)
{
	if (n - 1 > this->length || n < 0)
	{
		throw invalid_argument("Index is invalid");
	}

	return innerArray[n];
}

const int & DynamicArray::operator[](const int n) const
{
	if (n - 1 > this->length || n < 0)
	{
		throw invalid_argument("Index is invalid");
	}

	return innerArray[n];
}

int DynamicArray::binarySearch(int element) const
{
	int i = 0, dimension = getLength();
	int leftBorder = 0, rightBorder = dimension;
	for (i = 0; ; )
	{
		int middle = (leftBorder + rightBorder) / 2;
		if (this->innerArray[middle] == element)
		{
			cout << "The element has [" << middle + 1 << "] position in the array" << endl;
			break;
		}
		else if (element > this->innerArray[middle])
		{
			leftBorder = middle + 1;
		}
		else if (element < this->innerArray[middle])
		{
			rightBorder = middle - 1;
		}
		if (leftBorder > rightBorder)
		{
			cout << "No entered number in the array" << endl;
			break;
		}
	}
	return 0;
}

void DynamicArray::clear()
{
}

void DynamicArray::sort(int left, int right)
{
	if (right >= this->length - 1)
	{
		throw invalid_argument("Enter lesser range") ;
	}
	int i = left, j = right;
	int pivot = this->innerArray[(left + right) / 2];
	while (i <= j)
	{
		while (this->innerArray[i] < pivot)
		{
			i++;
		}
		while (this->innerArray[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(this->innerArray[i], this->innerArray[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		sort(left, j);
	}
	if (right > i)
	{
		sort(j, right);
	}

}

void DynamicArray::insertTo(int destination, int element)
{
	this->add(element);
	int length = this->getLength();
	for (int i = destination; i < length - destination ; i++)
	{
		swap(this->innerArray[i], this->innerArray[length - 1]);
	}

}


int DynamicArray::findMin() const
{
	int min = this->innerArray[0];
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->innerArray[i] < min)
		{
			min = this->innerArray[i];
		}
	}
	return min;
}

int DynamicArray::findMax() const
{
	int max = this->innerArray[0];
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->innerArray[i] > max)
		{
			max = this->innerArray[i];
		}
	}
	return max;
}

int * DynamicArray::allocateMemory(int n)
{
	if (n < 0)
	{
		throw invalid_argument("Length should be greater than 0");
	}

	int *a = new int[n] { 0 };

	return a;
}

void DynamicArray::resizeMemory(int *& source , int sourceLength, int destinationLength)
{

	int *tmp = allocateMemory(destinationLength);

	copyArray(source, sourceLength, tmp);

	delete[] source;

	source = tmp;
}

void DynamicArray::copyArray(int *source, int n, int *destination) //можно усовершенствовать
{
	for (unsigned int i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
}

ostream & operator<<(ostream &stream, const DynamicArray &array)
{
	for (int i = 0; i < array.getLength(); i++)
	{
		stream << array[i] << ' ';
	}

	stream << endl;
	
	return stream;
}

