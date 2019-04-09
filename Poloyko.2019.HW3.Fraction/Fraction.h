#pragma once
#include <iostream>

using namespace std;

class Fraction
{
	friend ostream& operator<<(ostream& , const Fraction& );
public:
	Fraction() : Fraction(1, 1) {}
	Fraction(int, unsigned int);
	~Fraction();
	int getNumerator() const;
	unsigned int getDenominator() const;
	void setFraction(int, unsigned int);
	void setNumerator(int);
	void setDenominator(unsigned int);
	bool isProper() const;
	void display() const;
	void reduce();
	static void toCommonDenominator(Fraction&, Fraction&);
	Fraction& operator=(const Fraction&);
	Fraction operator+(Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator-();
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	static bool isFirstGreater(Fraction, Fraction);
	int sign();

private:
	int numerator;
	unsigned int denominator;
	static unsigned int GCD(int, unsigned int);
	static unsigned int LCD(int, unsigned int);
};
