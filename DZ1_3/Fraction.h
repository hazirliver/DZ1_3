#pragma once
#include "Pair.h"
class Fraction :
	public Pair
{
private:
	long numerator;
	unsigned short denominator;
public:
	Fraction(long init_numerator = 0, unsigned short init_denominator = 1);
public:
	void write();
	void read();
	

	Fraction& operator + (const Fraction& other);
	Fraction& operator - (const Fraction& other);
	bool operator == (const Fraction& other);
	Fraction& operator / (const double frac);
	Fraction& operator * (const double frac);
	Fraction& operator = (const Fraction& other);

	int gcd(long nomerator, unsigned short denominator);

public:
	~Fraction();
};

