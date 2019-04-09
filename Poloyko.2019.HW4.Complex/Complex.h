#pragma once
#include <iostream>
using namespace std;

class Complex
{
	friend ostream& operator<<(ostream &, const Complex&);
public:
	Complex() : Complex(1, 1) {}
	Complex(double, double);
	~Complex();
	Complex conjugate();
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator-();
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);
	double getReal() const;
	double getImaginary() const;
private:
	void setReal(double);
	void setImaginary(double);
	void setComplex(double, double);
	double real, imaginary;
};