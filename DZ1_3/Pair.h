#pragma once
#include <algorithm>
#include <numeric>
class Pair
{
public:
	Pair();
public:
	
	virtual void write() = 0;
	virtual void read() = 0;


public:
	virtual ~Pair();
};

