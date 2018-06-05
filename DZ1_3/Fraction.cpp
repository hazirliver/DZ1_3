#include "Fraction.h"
#include <iostream>



Fraction::Fraction(long init_numerator, unsigned short init_denominator) : numerator(init_numerator), denominator(init_denominator)
{
	unsigned short gcd_buff = gcd(this->numerator, this->denominator);
	this->numerator /= gcd_buff;
	this->denominator /= gcd_buff;
}

void Fraction::write()
{
	if (this->denominator != 1)
	{
		std::cout << this->numerator << "/" << this->denominator << '\n';
	}
	else
	{
		std::cout << this->numerator << '\n';
	}
}

void Fraction::read()
{
	long read_numerator;
	unsigned short read_denominator;
	std::cout << "Введите числитель: ";
	std::cin >> read_numerator;
	std::cout << "Введител знаменатель: ";
	std::cin >> read_denominator;
	this->numerator = read_numerator;
	this->denominator = read_denominator;
	//
	unsigned short gcd_buff = gcd(this->numerator, this->denominator);
	this->numerator /= gcd_buff;
	this->denominator /= gcd_buff;
}

Fraction & Fraction::operator+(const Fraction & other)
{
	Fraction buff(this->numerator, this->denominator);
	if (this->denominator == other.denominator)
	{
		buff.numerator += other.numerator;
	}
	else
	{
		buff.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		buff.denominator *= other.denominator;
	}
	unsigned short gcd_buff = gcd(buff.numerator, buff.denominator);
	buff.numerator /= gcd_buff;
	buff.denominator /= gcd_buff;
	return buff;
}

Fraction & Fraction::operator-(const Fraction & other)
{
	Fraction buff(this->numerator, this->denominator);
	if (this->denominator == other.denominator)
	{
		buff.numerator += other.numerator;
	}
	else
	{
		buff.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		buff.denominator *= other.denominator;
	}
	unsigned short gcd_buff = gcd(buff.numerator, buff.denominator);
	buff.numerator /= gcd_buff;
	buff.denominator /= gcd_buff;
	return buff;
}

bool Fraction::operator==(const Fraction & other)
{
	return (this->numerator==other.numerator && this->denominator==other.denominator) ? 1 : 0;
}

Fraction & Fraction::operator/(const double frac)
{
	if (frac == 0)
	{
		std::cout << "Производится деление на ноль!";
		exit(1);
	}
	else
	{
		Fraction buff(this->numerator, this->denominator);
		buff.denominator /= frac;
		unsigned short gcd_buff = gcd(buff.numerator, buff.denominator);
		buff.numerator /= gcd_buff;
		buff.denominator /= gcd_buff;
		return buff;
	}
}

Fraction & Fraction::operator*(const double frac)
{
	Fraction buff(this->numerator, this->denominator);
	buff.denominator *= frac;
	unsigned short gcd_buff = gcd(buff.numerator, buff.denominator);
	buff.numerator /= gcd_buff;
	buff.denominator /= gcd_buff;
	return buff;
}

Fraction & Fraction::operator=(const Fraction & other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	unsigned short gcd_buff = gcd(this->numerator, this->denominator);
	this->numerator /= gcd_buff;
	this->denominator /= gcd_buff;
	return *this;
}

int Fraction::gcd(long numerator, unsigned short denominator)
{
	while (denominator != 0)
	{
		int t = denominator;
		denominator = numerator % denominator;
		numerator = t;
	}
	return numerator;
}

Fraction::~Fraction()
{
}
