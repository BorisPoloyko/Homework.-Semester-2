#include "Fraction.h"
#include <cmath>

Fraction::Fraction(int numerator, unsigned int denominator)
{
	if (numerator == denominator)
	{
		setFraction(1,1);
	}
	setFraction(numerator, denominator);
}
Fraction::~Fraction()
{
	cout << "This is the end!";
}

void Fraction::setNumerator(int a)
{
	numerator = a;
}

void Fraction::setDenominator(unsigned int b)
{
	if (b <= 0)
	{
		throw::invalid_argument("Denominator cannot be zero or less.");
	}
	denominator = b;
}

void Fraction::setFraction(int a, unsigned int b)
{
	setNumerator(a);
	setDenominator(b);
}

int Fraction::getNumerator() const
{
	return numerator;
}

unsigned int Fraction::getDenominator() const
{
	return denominator;
}

bool Fraction::isProper() const
{
	return (abs(numerator) < denominator) ? true : false;
}

void Fraction::display() const
{
	cout << numerator << " / " << denominator << endl;
}

unsigned int Fraction::GCD(int x, unsigned int y)
{
	x = abs(x);
	if (y == 0)
	{
		return x;
	}
	return GCD(y, x%y);
}

unsigned int Fraction::LCD(int x, unsigned int y)
{
	x = abs(x);
	return (x * y / GCD(x, y));
}

void Fraction::reduce()
{
	unsigned int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

void Fraction::toCommonDenominator(Fraction& fraction1, Fraction& fraction2)
{
	int a = fraction1.getNumerator(), c = fraction2.getNumerator();
	unsigned int b = fraction1.getDenominator(), d = fraction2.getDenominator();
	unsigned int commonDenominator = LCD(b, d);
	a *= (commonDenominator / b);
	c *= (commonDenominator / d);
	b = LCD(b, d), d = LCD(b, d);
	fraction1.setFraction(a, b);
	fraction2.setFraction(c, d);
}

Fraction Fraction::operator+(Fraction& fraction)
{
	toCommonDenominator(fraction, *this);
	return Fraction(fraction.getNumerator() + this->getNumerator(), fraction.getDenominator());
}

Fraction Fraction::operator-(Fraction& fraction)
{
	toCommonDenominator(fraction, *this);
	return Fraction(fraction.getNumerator() - this->getNumerator(), fraction.getDenominator());
}

Fraction Fraction::operator-()
{
	return Fraction((-this->getNumerator()), this->getDenominator());
}

Fraction Fraction::operator*(const Fraction& fraction)
{
	return Fraction(fraction.getNumerator() * this->getNumerator(), fraction.getDenominator() * this->getDenominator());
}

Fraction Fraction::operator/(const Fraction& fraction)
{
	return Fraction(fraction.getNumerator() * this->getDenominator(), fraction.getDenominator() * this->getNumerator());
}


bool Fraction::isFirstGreater(Fraction fraction1, Fraction fraction2)
{
	toCommonDenominator(fraction1, fraction2);
	return fraction1.getNumerator() > fraction2.getNumerator() ? true : false;
}

int Fraction::sign()
{
	return numerator >= 0 ? 1 : -1;
}

ostream & operator<<(ostream& stream, const Fraction& fraction)
{
	if (fraction.getDenominator() == 1)
	{
		return stream << fraction.getNumerator() << endl;
	}
	if (fraction.getDenominator() == fraction.getNumerator())
	{
		return stream << 1 << endl;
	}
	return stream << fraction.getNumerator() << " / " << fraction.getDenominator() << endl;
}

istream& operator>>(istream& stream, Fraction& fraction)
{
	cout << "Enter a numerator:";
	stream >> fraction.numerator;
	cout << "Enter a denominator: ";
	stream >> fraction.denominator;
	return stream;
}

Fraction& Fraction::operator=(const Fraction & fraction)
{
	setFraction(fraction.getNumerator(), fraction.getDenominator());
	return *this;
}
