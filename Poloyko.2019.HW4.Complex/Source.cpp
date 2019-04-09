#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	Complex complex1, complex2;
	int a, b;
	cout << "Enter real part: ";
	cin >> a;
	cout << "Enter imaginary part: ";
	cin >> b;
	complex1.setComplex(a, b);
	complex2.setComplex(a, b);
	cout << complex1;
	cout << complex2;
	Complex complex3;
	complex3 = complex1 / complex2;
	cout << complex3;
	
	system("pause");
}