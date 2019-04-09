#pragma once
#include <iostream>
using namespace std;

class Complex
{
	friend ostream& operator<<(ostream &, const Complex&);
	friend istream& operator>>(istream &, Complex&);
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
	void setComplex(double, double);
private:
	void setReal(double);
	void setImaginary(double);
	double real, imaginary;
};
