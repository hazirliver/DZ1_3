#include "Pair.h"
class Money : public Pair
{
private:
	unsigned char kopeck;
	long rubles;
public:
	Money(long init_rubles = 0, unsigned char init_kopeck = 0);
public:
	void write();
	void read();



	Money& operator + (const Money& other);
	Money& operator - (const Money& other);
	bool operator == (const Money& other);
	Money& operator / (const double frac);
	Money& operator * (const double frac);
	Money& operator = (const Money& other);



public:
	~Money();
};