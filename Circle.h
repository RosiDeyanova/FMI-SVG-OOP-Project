#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Circle:public Shape
{
private:
	int r;
	char fill[10];

public:
	Circle();
	Circle(int r, const char* fill);
	void print();
		


};

