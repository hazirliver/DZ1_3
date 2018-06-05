#include "Pair.h"
#include "Money.h"
#include "Fraction.h"
#include <iostream>



int main()
{
	setlocale(LC_ALL, "rus");
	Money A(0, 0);
	Money B(3, 77);
	Money C(159, 61);
	C = A + B;
	C.write();

	system("Pause");
}