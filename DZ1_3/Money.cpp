#include "Money.h"
#include <iostream>

Money::Money(long init_rubles, unsigned char init_kopeck) : kopeck((init_kopeck) % 100), rubles(init_rubles + (init_kopeck) / 100)
{
}

void Money::write()
{
	std::cout << this->rubles << "," << this->kopeck << '\n';
}

void Money::read()
{
	long read_rubles = 0;
	unsigned char read_kopeck = 0;
	std::cout << "¬ведите количество рублей: ";
	std::cin >> read_rubles;
	std::cout << "¬ведите количество копеек: ";
	std::cin >> read_kopeck;
	this->rubles = read_rubles + (read_kopeck / 100);
	this->kopeck = (read_kopeck) % 100;
}

Money & Money::operator+(const Money & other)
{
	Money buff(0, 0);
	buff.rubles = (this->rubles + other.rubles) + (this->kopeck + other.kopeck) / 100;
	buff.kopeck = (this->kopeck + other.kopeck) % 100;
	return buff;
}

Money & Money::operator-(const Money & other)
{
	Money buff(0, 0);
	buff.rubles = (this->rubles - other.rubles) - (this->kopeck - other.kopeck) / 100;
	buff.kopeck = (this->kopeck - other.kopeck) % 100;
	return buff;
}

bool Money::operator==(const Money & other)
{
	return this->rubles == other.rubles && this->kopeck == other.kopeck ? 1 : 0;
}

Money & Money::operator/(double frac)
{
	Money buff(0, 0);
	buff.kopeck = (int)((this->kopeck + this->rubles * 100) / frac);
	buff.rubles = buff.kopeck / 100;
	buff.kopeck = buff.kopeck % 100;
	return buff;
}

Money & Money::operator*(double frac)
{
	Money buff(0, 0);
	buff.kopeck = (this->kopeck + this->rubles * 100) * frac;
	buff.rubles = buff.kopeck / 100;
	buff.kopeck = buff.kopeck % 100;
	return buff;
}

Money & Money::operator=(const Money & other)
{
	this->rubles = other.rubles;
	this->kopeck = other.kopeck;
	return *this;
}



Money::~Money()
{
}
