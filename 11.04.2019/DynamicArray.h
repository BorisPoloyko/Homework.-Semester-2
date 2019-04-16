#pragma once
#include<iostream>

using namespace std;

class DynamicArray
{
	friend ostream& operator<<(ostream&, const DynamicArray&);
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	int getLength() const;
	void add(int);
	void remove(int);
	/*DynamicArray operator=(const DynamicArray&);*/
	int& operator[](const int);
	const int& operator[](const int) const;
	int binarySearch(int) const;
	void clear();
	void sort(int,int);
	void insertTo(int, int);
	int findMin() const;
	int findMax() const;
private:
	const int defaultCapacity = 4;
	const int growthFactor = 2;
	int *innerArray;
	int length;
	int capacity;
	static int* allocateMemory(int);
	static void resizeMemory(int*&, int, int);
	static void copyArray(int*, int, int*);
	void setLength(int);
};

