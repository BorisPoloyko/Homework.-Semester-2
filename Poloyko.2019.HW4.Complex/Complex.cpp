#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double real, double imaginary)
{
	setComplex(real, imaginary);
}

void Complex::setReal(double a)
{
	real = a;
}

void Complex::setImaginary(double b)
{
	
	imaginary = b;
}

void Complex::setComplex(double a, double b)
{
	setReal(a);
	setImaginary(b);
}

double Complex::getReal() const
{
	return real;
}

double Complex::getImaginary() const
{
	return imaginary;
}

Complex::~Complex()
{
	cout << "This is the end!";
}

Complex Complex::conjugate()
{
	imaginary = -imaginary;
	Complex conjugate;
	conjugate.setComplex(real, imaginary);
	return conjugate;
}

Complex Complex::operator+(const Complex& complex)
{
	return Complex(complex.getReal()+ this->getReal(), complex.getImaginary()+ this->getImaginary());
}

Complex Complex::operator-(const Complex& complex)
{
	return Complex(complex.getReal() - this->getReal(), complex.getImaginary() - this->getImaginary());
}

Complex Complex::operator-()
{
	return Complex(-(this->getReal()), -(this->getImaginary()));
}

Complex Complex::operator*(const Complex& complex)
{
	return Complex(complex.getReal() * this->getReal() - complex.getImaginary() * this->getImaginary() , complex.getReal() * this->getImaginary() + this->getReal() * complex.getImaginary());
}

Complex Complex::operator/(const Complex& complex)
{
	double a1 = complex.getReal(), a2 = this->getReal(), b1 = complex.getImaginary(), b2 = this->getImaginary();
	return Complex((a1 * a2 + b1 * b2) / (pow(a2, 2) + pow(b2, 2)), ((a2 * b1 - a1 * b2) / (pow(a2, 2) + pow(b2, 2))));
}

ostream& operator<<(ostream& stream, const Complex& complex)
{
	if (complex.getImaginary() > 0 && complex.getReal() != 0)
	{
		return stream << complex.getReal() << " + " << complex.getImaginary() << "i" << endl;
	}
	if (complex.getImaginary() < 0 && complex.getReal() != 0)
	{
		return stream << complex.getReal() << " - " << abs(complex.getImaginary()) << "i" << endl;
	}
	if (complex.getReal() == 0 && complex.getImaginary() == 0)
	{
		return stream << 0;
	}
	if (complex.getReal() == 0)
	{
		return stream << complex.getImaginary() << "i" << endl;
	}
	if (complex.getImaginary() == 0)
	{
		return stream << complex.getReal() << endl;
	}
}

istream& operator>>(istream & stream, Complex& complex)
{
	cout << "Input real part: ";
	stream >> complex.real;
	cout << "Input imaginary part: ";
	stream >> complex.imaginary;
	return stream;
}
