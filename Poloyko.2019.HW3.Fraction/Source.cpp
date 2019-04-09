#include <iostream>
#include "Fraction.h"

using namespace std;

typedef bool(*Predicate)(Fraction);
typedef int(*Key)(Fraction);

Fraction findFraction(Fraction*,int, Predicate);
void quickSort(Fraction*, int, int, Key);

int inputSize();
Fraction* allocateMemory(int);
bool isPositive(Fraction);
void display(Fraction*, int);
void setArrayFractions(Fraction*, int);
int sign(Fraction);

int main()
{

	Fraction fraction1, fraction2, fraction3;
	cin >> fraction1;
	cin >> fraction2;
	cout << fraction1;
	cout << fraction2;
	fraction3 = fraction1 / fraction2;
	cout << fraction3;
	
	system("pause");
	return 0;
}

Fraction findFraction(Fraction* fractions, int n, Predicate predicate)
{
	if (fractions == nullptr)
	{
		throw invalid_argument("Array cannot be null.");
	}
	if (n <= 0)
	{
		throw invalid_argument("Number of elements cannnot be less than 0.");
	}
	for (size_t i = 0; i < n; i++)
	{
		if (predicate(fractions[i]))
		{
			return fractions[i];
		}
	}
	cout << "No fraction found!" << endl;
	
}

bool isPositive(Fraction fraction)
{
	return fraction.sign() == 1 ? true : false;
}

Fraction* allocateMemory(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("Number of elements cannnot be less than 0.");
	}
	return new Fraction[n];
}

void display(Fraction* fractions, int n)
{
	if (fractions == nullptr)
	{
		throw invalid_argument("Array cannot be null.");
	}
	if (n <= 0)
	{
		throw invalid_argument("Number of elements cannnot be less than 0.");
	}
	for (size_t i = 0; i < n; i++)
	{
		fractions[i].display();
	}
}

int sign(Fraction fraction)
{
	return fraction.getNumerator() >= 0 ? 1 : -1;
}

void setArrayFractions(Fraction* fractions, int n)
{
	int a, b;
	if (fractions == nullptr)
	{
		throw invalid_argument("Array cannot be null.");
	}
	if (n <= 0)
	{
		throw invalid_argument("Number of elements cannnot be less than 0.");
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		fractions[i].setFraction(a,b);
	}
}

int inputSize()
{
	int n;
	cout << "Please enter size of Array: ";
	cin >> n;
	if (n <= 0)
	{
		throw invalid_argument("Size cannot be less 0.");
	}
	return n;
}

void quickSort(Fraction* fractions, int left, int right, Key key)
{
	if (fractions == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}
	int i = left, j = right;
	Fraction pivot = fractions[(left + right) / 2];
	while (i <= j)
	{
		while (key(fractions[i]) < key(pivot))
		{
			i++;
		}
		while (key(fractions[j]) > key(pivot))
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(fractions[i], fractions[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSort(fractions, left, j, key);
	}
	if (right > i)
	{
		quickSort(fractions, j, right, key);
	}
}

