#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Line:public Shape
{
private:
	int x2;
	int y2;
public:
	Line();
	Line(int x2, int y2);
	void print();
};

